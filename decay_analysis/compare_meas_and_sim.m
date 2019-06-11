
% Plot detector data
load('co-57.mat');
figure(1); subplot(2,1,1);
hist(E, Evec)
ylabel("Counts")
xlim([0 200])
grid();
title("Detector Data")


%%

simulation_energy = importfile_hits_csv("../data/hits.csv");

%%

hitsMultiplier = 8;

subplot(2,1,2);
histogram(simulation_energy, Evec)
xlim([0 200])
xlabel("Energy (keV)")
ylabel("Counts")
grid();
