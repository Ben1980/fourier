reset
#set encoding utf8
#set terminal svg enhanced fname 'Times New Roman' rounded dashed standalone
set terminal png giant
set xrange [0:4.5*pi]
#set xtics ("" 0, "Π" pi, "2Π" 2*pi, "3Π" 3*pi, "4Π" 4*pi)
set xtics ("" 0, "PI" pi, "2PI" 2*pi, "3PI" 3*pi, "4PI" 4*pi)
set xzeroaxis

set yrange [-1.5:1.5]
set ytics ("-1" -1, "" 0, "1" 1)

set samples 2001
set key off

set output "images/square.png"
square(x) = sgn(sin(x))
plot square(x) lw 2 linetype 1

set output "images/f1.png"
f1(x) = 4.0/pi * sin(x)
plot square(x) lw 2 linetype 1, f1(x) lw 2 linetype 2

set output "images/f2.png"
f2(x) = 4.0/pi * (sin(x) + 1.0/3.0*sin(3.0*x))
plot square(x) lw 2 linetype 1, f2(x) lw 2 linetype 3

set output "images/f3.png"
f3(x) = 4.0/pi * (sin(x) + 1.0/3.0*sin(3.0*x) + 1.0/5.0*sin(5.0*x))
plot square(x) lw 2 linetype 1, f3(x) lw 2 linetype 4

set output "images/f4.png"
f4(x) = 4.0/pi * (sin(x) + 1.0/3.0*sin(3.0*x) + 1.0/5.0*sin(5.0*x) + 1.0/7.0*sin(7.0*x))
plot square(x) lw 2 linetype 1, f4(x) lw 2 linetype 5

set output "images/f5.png"
f5(x) = 4.0/pi * (sin(x) + 1.0/3.0*sin(3.0*x) + 1.0/5.0*sin(5.0*x) + 1.0/7.0*sin(7.0*x) + 1.0/9.0*sin(9.0*x))
plot square(x) lw 2 linetype 1, f5(x) lw 2 linetype 6


set output "images/order0.png"
f0(x) = 4.0/pi
plot f0(x) lw 2 linetype 1

set output "images/order1.png"
f1(x) = sin(x)
plot f1(x) lw 2 linetype 2

set output "images/order2.png"
f2(x) = 1.0/3.0*sin(3.0*x)
plot f2(x) lw 2 linetype 3

set output "images/order3.png"
f3(x) = 1.0/5.0*sin(5.0*x)
plot f3(x) lw 2 linetype 4

set output "images/order4.png"
f4(x) = 1.0/7.0*sin(7.0*x)
plot f4(x) lw 2 linetype 5

set output "images/order5.png"
f4(x) = 1.0/9.0*sin(9.0*x)
plot f4(x) lw 2 linetype 6
