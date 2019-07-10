
% Plot detector data
load('co-57.mat');
clf; figure(1); subplot(2,1,1);
histogram(E, Evec, 'Normalization', 'Probability')
set(gca, 'YScale', 'linear')
ylabel("Counts")
xlim([0 200])
grid();
title("Detector Data")


%%

sim_data = importfile_e_pos_csv("../data/hits.csv");
sim_data.hits = sim_data.x;
sim_data.x = [];
sim_data.y = [];
sim_data.z = [];

%%

energyThreshold1 = 50;

figure(1); subplot(2,1,2);
histogram(sim_data.hits(sim_data.hits > energyThreshold1), ...
    Evec, 'Normalization', 'Probability');
set(gca, "YScale", "linear")
xlim([0 200])
title("Simulation Data")
xlabel("Energy (keV)")
ylabel("Counts")
grid();


%%

scale = 'log';

energyThreshold1 = 50;
nBins = 1000;
figure(2); clf; hold on; grid on;
histogram(E, Evec, 'Normalization', 'Probability')
set(gca, 'YScale', scale)
ylabel("Counts")
xlim([0 200])
title("Co-57 CZT Response")

histogram(sim_data.hits(sim_data.hits > energyThreshold1), ...
        Evec,  'Normalization', 'Probability');
set(gca, "YScale", scale)
xlim([0 200])
xlabel("Energy (keV)")
ylabel("Normalized Counts")

legend(["Detector data","Simulated data"]);

