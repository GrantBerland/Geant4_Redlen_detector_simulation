

d_source = 10;  % cm

d_det  = 3.9;   % cm
d_slit = 0.2;   % cm

solidAng_det  = d_det^2 / d_source;
solidAng_slit = d_det * d_slit / d_source;

branchingRatio_122keV = 0.89;
branchingRatio_14_4keV = 0.092;

decayRate_co57 = 1.85E9;  % Bq
Bq2Ci = 3.7E10;           % decays/s into 4pi sr


flux_det_122keV = decayRate_co57 * Bq2Ci * (solidAng_det / 4 * pi) ...
                    * branchingRatio_122keV;
                
flux_slit_122keV = decayRate_co57 * Bq2Ci * (solidAng_slit / 4 * pi) ...
                    * branchingRatio_122keV;
                
fprintf("Photon (122 keV) flux on detector: %.2e /s/cm^2\n", flux_det_122keV)

fprintf("Photon (122 keV) flux through slit: %.2e /s/cm^2\n", flux_slit_122keV)
