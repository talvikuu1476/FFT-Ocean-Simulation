# FFT Wave Simulation
![wave](https://github.com/user-attachments/assets/c1922c86-f189-4470-a475-c649166b46b0)

This plugin is developed under UE 5.6 environment.

## How to Use

Apply the wave material (MI_WaveSurface0) to the wave grid.

### Adjustable params

#### M_WaveSurface0_Inst

1. UVScale

UV scale. Default 1.

2. WaveStrength

Wave strength. Default 1500.

#### Wave Grid

1. Num Verts

Number of vertices. Default 128, minimum 2 and maximum 512.

2. Grid Spacing

Wave area or distance between vertices. Default 50, minimum 1 and maximum 1000.

# Instructions

## Shaders

### 1. InitialSpectrum.usf
This shader generates the initial wave. It ouputs 3 resources for further computation:
#### H0K
Initial spectrum.

#### WavesData
Wave vector and frequency data (kx + ampScale + kz + omega).

#### H0
Conjugated spectrum for FFT symmetry.

### 2. TwiddleFactor.usf
This shader generates the twiddle factor as the pre-compute LUT for transforming wave data from frequency domain to spatial domain.

### 3. IFFTFrequency.usf
This shader transforms static frequnecy domain wave data into time-involved wave displacements and corresponding derivatives. It ouputs 4 resources:

#### Dy_Dx
X and Z displacement.

#### Dy_Dxz
Y displacement (wave height) + X and Z derivatives (using this to calculate Jacobian).

#### Dyx_Dyz
Y derivatives with respect to X and Z (using this to calculate wave normal)

#### Dxx_Dzz
second-order X and Z derivatives (using this to calculate wave normal)

### 4. IFFTButterfly.usf
This shader performs the IFFT butterfly operations. It executes one stage of the IFFT algorithm and the actual iteration process is handled in the related pass. It takes 1 derivative calculated in IFFTFrequency.usf as initial data each time (4 in total) and outputs the result after completing iteration.

### 5. WaveIntegration.usf
This shader integrates IFFT-transformed wave data (including displacement and derivatives) and packages them into 3 render targets as displacement texture, normal texture and foam texture. These 3 RTs could be sampled across material editorand applied on a grid to simulate realsitic waves.


## Render Pipeline

This project uses UE5's default deferred rendering pipeline.

### 0. H0k

Setup spectrum params through blueprint and generate static initial wave spectrum (H0k). It didn't added to the RDG so you need to render it prior to other passes (H0, WavesData, and TwiddleFactor in this stage).

### 1. InitialSpectrum & TwiddleFactor

Draw conjugated spectrum (H0), wave vector and frequency data (WavesData), and twiddle factor to RTs. These 3 RTs will be removed from RDG and precomputed prior to other passes later for optimisation.

### 2. Frequency (IFFT Frequency)

Compute the time-dependent spectrum and derivatives by evolving frequency domain data per frame and draw them on 4 RTs as frequency doamin textures separately.

### 3. IFFTButterfly

Transform frequency domain data to spatial domain data (e.g. displacements and heights) using IFFT butterfly for each frequency domain texture.

### 4. WaveIntegration

Use spatial domain data to create displacement texture, normal texture, and foam texture (didn't used in this project).

## Features

### 1. Procedural Grid Mesh

A runtime-generated regular 2D grid in the XZ plane. Each vertex initially has position (x, 0, z), UV coords for sampling displacement and normal textures, and tangents for normal computation. 

### 2. EngineSubSystem

The UWvaeEnigneSubsystem manages all GPU resources, simulation paramenters and per-frame compute shader passes, building and submitting the RDG sequence for evolving waves.

Diagram of Flow via Subsystem:

        ├── UWaveEngineSubsystem
        
        └──

                ├── Allocates GPU textures & UAVs
                
                ├── Stores simulation parameters (wind, FFT size)
                
                ├── Updates time per frame
                
                │
                
                └── OnRenderTick → Build RDG:
                
                        ├── InitialSpectrum & TwiddleFactor (H0, WavesData, TwiddleFactor, WILL BE REMOVED FROM THE RDG LATER)
                        
                        ├── IFFTFrequency (time evolution in frequency domain)
                        
                        ├── IFFTButterfly X/Y stages
                        
                        └── WaveIntegration → Displacement/Normal/Foam RTs
                        
                │
                
                └── Exposes textures to materials for rendering ocean mesh


### 3. BlueprintFunctionLibrary

A static class to expose static utility function to blueprint in Unreal Editor. It has several adjustable params including:

1. SpectrumData

An array (FSpectrumParameters) containing a group of basic wave spectrum params. Specifically,

        scale: Wave intensity. Default 1.0.
        angle: Dominant wave direction (radians). Default 0.0.
        spreadBlend: Direction spreading. 0 = narrow spread; 1 = wide spread. Default 0.5.
        swell: Optional. Swell wave intensity. Default 0.0.
        alpha: Phillips spectrum constant (≈0.0081 in Pierson–Moskowitz model). Default 0.0081.
        peakOmega: The peak angular frequrncy (radians/sencond). Default 0.855.
        gamma: JONSWAP spectrum param. Default 3.3 (also the default value in JONSWAP spectrum).
        shortWavesFade: Dampens short, high-frequency waves. Default 0.01, range typically 0-1.
        
 
3. NoiseTexture

A 256 * 256 noise texture. For this project a pre-computed gaussian noise with RGBA channel.

4. WaveSize

Wave size or the FFT resolution. Default 256.0 (will draw on a 256 * 256 RT).  

6. WaveLengthScale = 1000.0f,

The physical scale of the simulation domain. Default 1000.0.

7. WaveCutoffHigh

High-frequency cutoff in the spectrum. Default 10000.0.

8. WaveCutoffLow 

HLow-frequency cutoff in the spectrum. Default 0.0001.

9. WaveGravityAcceleration

Gravitational acceleration (in cm/s^2) Default 981.0, mostly it shouldn't be adjusted.

10. WaveDepth (cm)

Wave depth or water depth. Default 50.0, simulating a 0.5m shallow water condition.

