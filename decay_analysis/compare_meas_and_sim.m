
% Plot detector data
load("co-57.mat")
figure(1); subplot(2,1,1);
hist(E, Evec)
ylabel("Counts")
xlim([0 200])
grid();
title("Detector Data")

subplot(2,1,2); hold on; grid on;
%%
% Import data after simulation run
rdecay02h1H10 = importfile("../build/rdecay02_h1_H10.csv");
rdecay02h1H11 = importfile("../build/rdecay02_h1_H11.csv");
rdecay02h1H16 = importfile("../build/rdecay02_h1_H16.csv");

%%

ignoreBefore = 30;
scaleFactor = 1;

% Plot simulation data
subplot(2,1,2); 

E_vec_geant = linspace(0, 300, 502);

%{
bar(E_vec_geant(ignoreBefore:end), ...
    rdecay02h1H16(ignoreBefore:end,1).*scaleFactor, ... 
    2, 'b');
%}
hold on;
bar(E_vec_geant(ignoreBefore:end), ...
    rdecay02h1H16(ignoreBefore:end,1).*scaleFactor, ... 
    2, 'r');
hold off;
xlabel("Energy Bin (keV)")
ylabel("Counts")
xlim([0 200])

%legend(["\gamma Co-57",...
%        "\gamma detector"]);
title("Simulated Detector Data")

