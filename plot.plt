set term pdfcairo size 10cm, 8cm font ',9' rounded
#set term png
set output "res.pdf"

set style line 1 lt 1 lc rgb '#352a87' pt 1 ps 0.1
set style line 2 lt 1 lc rgb '#F72323' pt 1 ps 0.1

set grid
set key box
set key top right

file1 = "in.dat"
file2 = "out.dat"

plot file1 u 1:2 w p ls 1,  file2 u 1:2 w p ls 2
