
% Plot detector data
figure(1); subplot(2,1,1);
hist(E, Evec)
ylabel("Counts")
xlim([0 200])
grid();
title("Detector Data")
%%
% Import data after simulation run
rdecay02h1H10 = importfile("../build/rdecay02_h1_H10.csv");
rdecay02h1H11 = importfile("../build/rdecay02_h1_H11.csv");
rdecay02h1H16 = importfile("../build/rdecay02_h1_H16.csv");

%%

ignoreBefore = 30;
scaleFactor = 8;

% Plot simulation data
subplot(2,1,2)
E_vec_geant = linspace(0, 500, 702);

bar(E_vec_geant(ignoreBefore:end), ...
    rdecay02h1H10(ignoreBefore:end,1).*scaleFactor, ... 
    2);

xlabel("Energy Bin (keV)")
ylabel("Counts")
xlim([0 200])
grid();
title("Simulated Detector Data")

