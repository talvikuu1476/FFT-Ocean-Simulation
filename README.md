# FFT Wave Simulation
This plugin is developed under UE 5.6 environment.

## Shaders
### 1. InitialSpectrum.usf
This shader generates the initial wave. It ouputs 3 resources for further computation:
#### H0K
Initial spectrum.

#### WavesData
Wave vector and frequency data (kx + ampScale + kz + omega).

#### H0
Conjugate spectrum for FFT symmetry.


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

TODO


