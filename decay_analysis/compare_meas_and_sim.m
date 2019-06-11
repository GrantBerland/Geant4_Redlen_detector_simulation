
% Plot detector data
load('co-57.mat');
figure(1); subplot(2,1,1);
histogram(E, Evec)
ylabel("Counts")
xlim([0 200])
grid();
title("Detector Data")


%%

simulation_energy = importfile_hits_csv("../data/hits.csv");

%%

subplot(2,1,2);
h = histogram(simulation_energy, Evec);
%bar(h.Values, h.BinWidth)
xlim([0 200])
xlabel("Energy (keV)")
ylabel("Counts")
grid();
