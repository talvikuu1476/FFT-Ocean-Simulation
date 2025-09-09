# FFT Wave Simulation
![wave](https://github.com/user-attachments/assets/c1922c86-f189-4470-a475-c649166b46b0)

This plugin is developed under UE 5.6 environment.

## How to Use

Apply the wave material (M_WaveSurface0_Inst) to the wave grid.

### Adjustable params

#### M_WaveSurface0_Inst

1. UVScale

UV scale. Default 1.

2. WaveStrength

Wave strength. Default 1500.

#### Wave Grid

1. Num Verts

Number of vertices

2. Grid Spacing. Default 128, minimum 2 and maximum 512.

Wave area. Default 50, minimum 1 and maximum 1000.

# Explanation

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

### 1. Procedurally Generated Grid









