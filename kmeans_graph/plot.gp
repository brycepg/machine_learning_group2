set datafile separator ","
unset colorbox
set title "Random Data - Clusters"
set xlabel "X value"
set ylabel "Y value"
plot 'data_n_assignments.csv' using 1:2:3 with points pt 7 ps 1 palette notitle, 'centroids.csv' using 1:2 pt 5 notitle
pause -1


set term png
set output "tmp_plot.png"
replot
set term x11
