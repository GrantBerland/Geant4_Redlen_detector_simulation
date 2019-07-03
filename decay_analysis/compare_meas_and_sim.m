
% Plot detector data
load('co-57.mat');
figure(1); subplot(2,1,1);
histogram(E, Evec, 'Normalization', 'Probability')
set(gca, 'YScale', 'linear')
ylabel("Counts")
xlim([0 200])
grid();
title("Detector Data")


%%

sim_data = importfile_e_pos_csv("../data/hits.csv");

%%

energyThreshold1 = 50;

subplot(2,1,2);
histogram(sim_data.hits(sim_data.hits > energyThreshold1), ...
    Evec)%, 'Normalization', 'Probability');
set(gca, "YScale", "linear")
xlim([0 200])
title("Simulation Data")
xlabel("Energy (keV)")
ylabel("Counts")
grid();

%%

energy_threshold2 = 50;

% Plot both data sets superimposed
figure(); grid on; hold on;
histogram(E, Evec, 'Normalization', 'Probability');
histogram(sim_data.hits(sim_data.hits > energy_threshold2), ...
Evec, 'Normalization', 'Probability');
legend(["Detector","Simulation"]);
xlim([0 200]);
xlabel("Energy (keV)");
ylabel("Counts");

%%

figure();
hist3([sim_data.y, sim_data.z], [16, 16]);
xlabel("Y (cm)"); ylabel("Z (cm)")

