## FFT Wave Simulation
This plugin is developed under UE 5.6 environment.

### Shader Explanation
1. InitialSpectrum.usf
This shader generates the initial wave. It ouputs 3 resources for further computation:


2. TwiddleFactor.usf


3. IFFTButterfly.usf


4. IFFTFrequency.usf


5. WaveIntegration.usf






