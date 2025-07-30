# FFT Wave Simulation
This plugin is developed under UE 5.6 environment.

## Shader Explanation
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


### 3. IFFTButterfly.usf
This shader performs the IFFT butterfly operations.


### 4. IFFTFrequency.usf



### 5. WaveIntegration.usf







