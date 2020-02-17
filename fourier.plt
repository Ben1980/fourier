reset
set terminal png giant
set xrange [0:4.5*pi]
set xtics ("" 0, "PI" pi, "2PI" 2*pi, "3PI" 3*pi, "4PI" 4*pi)
set xzeroaxis

set yrange [-0.5:2.5]
set ytics ("0" 0, "1" 1, "2" 2)

set samples 2001
set key off

set output "images/square.png"
square(x) = sgn(sin(x)) + 1
plot square(x) lw 2 linetype 1

set output "images/f1.png"
f1(x) = 2/2 + 2*2/pi * sin(x)
plot square(x) lw 2 linetype 1, f1(x) lw 2 linetype 2

set output "images/f2.png"
f2(x) = 2/2 + 2*2/pi * (sin(x) + 1.0/3.0*sin(3.0*x))
plot square(x) lw 2 linetype 1, f2(x) lw 2 linetype 3

set output "images/f3.png"
f3(x) = 2/2 + 2*2/pi * (sin(x) + 1.0/3.0*sin(3.0*x) + 1.0/5.0*sin(5.0*x))
plot square(x) lw 2 linetype 1, f3(x) lw 2 linetype 4

set output "images/f4.png"
f4(x) = 2/2 + 2*2/pi * (sin(x) + 1.0/3.0*sin(3.0*x) + 1.0/5.0*sin(5.0*x) + 1.0/7.0*sin(7.0*x))
plot square(x) lw 2 linetype 1, f4(x) lw 2 linetype 5

set output "images/f5.png"
f5(x) = 2/2 + 2*2/pi * (sin(x) + 1.0/3.0*sin(3.0*x) + 1.0/5.0*sin(5.0*x) + 1.0/7.0*sin(7.0*x) + 1.0/9.0*sin(9.0*x))
plot square(x) lw 2 linetype 1, f5(x) lw 2 linetype 6

set yrange [-1.5:1.5]
set ytics ("-1" -1, "0" 0, "1" 1)

set key on
set output "images/harmonic0.png"
f1(x) = 2/2
plot f1(x) lw 2 linetype 1 title "static component"

set output "images/harmonic1.png"
f1(x) = 2*2/pi*sin(x)
plot f1(x) lw 2 linetype 2 title "basic oscillation component"

set output "images/harmonic2.png"
f2(x) = 2*2/pi*1.0/3.0*sin(3.0*x)
plot f2(x) lw 2 linetype 3 title "1st harmonic component"

set output "images/harmonic3.png"
f3(x) = 2*2/pi*1.0/5.0*sin(5.0*x)
plot f3(x) lw 2 linetype 4 title "2nd harmonic component"

set output "images/harmonic4.png"
f4(x) = 2*2/pi*1.0/7.0*sin(7.0*x)
plot f4(x) lw 2 linetype 5 title "3rd harmonic component"

set output "images/harmonic5.png"
f4(x) = 2*2/pi*1.0/9.0*sin(9.0*x)
plot f4(x) lw 2 linetype 6 title "4th harmonic component"

set key off
set yrange [0:1.5]
set ytics auto
set xrange [0:16]
set xtics ("" 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, "" 16)
set boxwidth 0.5
set style fill solid

set samples 15
set output "images/amplitudeSpectrum.png"
plot "squareWave.dat" with boxes

#This seems necessary otherwyse the ladt generate png is corrupt
set output "images/dummy.png"
plot 1
