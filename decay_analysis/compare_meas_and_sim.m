
% Plot detector data
load('co-57.mat');
clf; figure(1); subplot(2,1,1);
histogram(E, Evec, 'Normalization', 'countdensity')
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


energyThreshold1 = 0;

figure(1); subplot(2,1,2);
histogram(sim_data.hits(sim_data.hits > energyThreshold1), ...
    Evec, 'Normalization', 'countdensity');
set(gca, "YScale", "linear")
xlim([0 200])
title("Simulation Data")
xlabel("Energy (keV)")
ylabel("Counts")
grid();


scale = 'log';


figure(2); clf; subplot(2,1,1); hold on; grid on;
hData = histogram(E, Evec, 'Normalization', 'countdensity');
set(gca, 'YScale', scale)
ylabel("Counts")
xlim([0 200])
title("Co-57 CZT Response")

hSim = histogram(sim_data.hits(sim_data.hits > energyThreshold1), ...
        Evec,  'Normalization', 'countdensity');
set(gca, "YScale", scale)
xlim([0 200])
xlabel("Energy (keV)")
ylabel("Normalized Counts")

legend(["Detector data","Simulated data"]);

figure(2); subplot(2,1,2);
unexplainedSig = abs(hData.Values - hSim.Values);
bar(unexplainedSig);
set(gca, 'YScale','log');
xlim([0 200]); grid on;
xlabel("Energy (keV)")
ylabel("|Data - Simulation|")

