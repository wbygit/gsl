#!/usr/bin/env gnuplot

set term pngcairo enhanced monochrome

outdir = '../images/'

set samples 300
set tics out
#set ticscale 0.5 0.25
set xtics border nomirror norotate
set ytics border nomirror norotate
set format x "%g"

# Continuous distributions

set xlabel "x"
set ylabel "p(x)"

set xrange [-5:5]
set yrange [0:0.5]
set ytics 0.1
set xtics 1
set output outdir . 'rand-gaussian.png'
set title "Gaussian Distribution"
p(x)=1/sqrt(2*pi*sigma**2)*exp(-x**2/(2*sigma**2))
plot sigma=1.0, p(x) title "{/Symbol \163}=1", \
     sigma=2.0, p(x) title "{/Symbol \163}=2"

set xrange [0:5]
set yrange [0:2]
set ytics 0.5
set xtics 1
set output outdir . 'rand-gaussian-tail.png'
set title "Gaussian Tail Distribution"
p(x)= x > a ? 1/(0.5*erfc(a/sqrt(2*sigma**2))*sqrt(2*pi*sigma**2))*exp(-x**2/(2*sigma**2)) : 0
plot a=1.5, sigma=1.0, p(x) title "\{/Symbol \163}=1,a=1.5"

set xrange [0:5]
set yrange [0:1.09]
set ytics 0.5
set xtics 1
set output outdir . 'rand-rayleigh-tail.png'
set title "Rayleigh Tail Distribution"
p(x)= x > a ? (x/sigma**2)*exp((a**2 - x**2)/(2*sigma**2)) : 0
plot a=1.0, sigma=1.0, p(x) title "a=1,\{/Symbol \163}=1", \
     a=0.5, sigma=2.0, p(x) title "a=0.5,\{/Symbol \163}=2"

set xlabel "x"
set ylabel "y"
set xrange [-2:2]
set yrange [-2:2]
set ytics 1
set xtics 1
set output outdir . 'rand-bivariate-gaussian.png'
set title "Bivariate Gaussian Distribution"
set isosamples 30
p(x,y)=1/sqrt(2*pi*sqrt(1-rho**2))*exp(-(x**2 + y**2 - 2*rho*x*y)/(2*(1-rho**2)))
#set cntrparam cspline
set noclabel
set contour
set view map
set nosurface
splot rho=0.9, p(x,y) title "\{/Symbol \163}_x=1, \{/Symbol \163}_y=1, \\rho=0.9"

set xlabel "x"
set ylabel "p(x)"
set ytics 0.1
set xrange [-5:5]
set yrange [0:0.4]
set output outdir . 'rand-cauchy.png'
set title "Cauchy Distribution"
p(x)=1/(pi*a*(1+(x/a)**2))
plot a=1.0, p(x) title "a=1", \
     a=2.0, p(x) title "a=2"

set ytics 0.5
set yrange [0:1]
set xrange [0:3]
set output outdir . 'rand-exponential.png'
set title "Exponential Distribution"
p(x)=exp(-x/mu)/mu
plot mu=1.0, p(x) title "{/Symbol \155}=1", \
     mu=2.0, p(x) title "{/Symbol \155}=2"

set yrange [0:1]
set xrange [0:3]
set output outdir . 'rand-chisq.png'
set title "Chi-squared Distribution"
p(x)=(x/2)**(nu/2.0-1.0) *exp(-x/2)/ (2*gamma(nu/2.0))
plot nu=1.0, p(x) title "{/Symbol \156}=1", \
     nu=2.0, p(x) title "{/Symbol \156}=2", \
     nu=3.0, p(x) title "{/Symbol \156}=3"

set yrange [0:1]
set xrange [0:5]
set output outdir . 'rand-erlang.png'
set title "Erlang Distribution"
p(x)=x**(n-1) *exp(-x/a)/ (gamma(n)*a**n)
plot n=1.0, a=1, p(x) title "n=1", \
     n=2.0, a=1.0, p(x) title "n=2", \
     n=3.0, a=1.0, p(x) title "n=3"

set xrange [0:2]
set xtics 1
set output outdir . 'rand-fdist.png'
set title "F-Distribution"
p(x)=gamma((v1+v2)/2.0)*v1**(v1/2.0)*v2**(v2/2.0)\
	/gamma(v1/2.0)/gamma(v2/2.0) * \
	x**(v1/2.0-1)*(v2+v1*x)**-(v1/2.0+v2/2.0)
plot v1=1.0, v2=1.0, p(x) title "{/Symbol \156}_1=1, {/Symbol \156}_2=1", \
     v1=3.0, v2=1.0, p(x) title "{/Symbol \156}_1=3, {/Symbol \156}_2=2"

set xrange [0:5]
set output outdir . 'rand-flat.png'
set title "Flat Distribution"
p(x)= (x<b && x>a) ? 1/(b-a) : 0
plot a=0.5, b=2.5, p(x) title "a=0.5,b=2.5" with step, \
     a=1.2, b=4.8, p(x) title "a=1.2,b=4.8" with step

set xrange [0:5]
set yrange [0:1]
set ytics 0.5
set output outdir . 'rand-gamma.png'
set title "Gamma Distribution"
p(x)= x**(a-1)* exp(-x) / gamma(a)
plot a=1.0, p(x) title "a=1", \
     a=2.0, p(x) title "a=2", \
     a=3.0, p(x) title "a=3"

set xrange [0:1]
set yrange [0:4]
set xtics 0.25
set ytics 1
set output outdir . 'rand-beta.png'
set title "Beta Distribution"
p(x)= gamma(a+b)/(gamma(a)*gamma(b))*x**(a-1)*(1-x)**(b-1)
plot a=2.0, b=2.0, p(x) title "a=2,b=2", \
     a=4.0, b=1.0, p(x) title "a=4,b=1", \
     a=1.0, b=4.0, p(x) title "a=1,b=4"

set xrange [-5:5]
set yrange [0:0.3]
set ytics 0.1
set xtics 1
set output outdir . 'rand-logistic.png'
set title "Logistic Distribution"
p(x)= exp(-x/a)/a/(1+exp(-x/a))**2
plot a=1.0, p(x) title "a=1", \
     a=2.0, p(x) title "a=2"

set xrange [0:3]
set yrange [0:0.7]
set xtics 1
set ytics 0.5
set output outdir . 'rand-lognormal.png'
set title "Lognormal Distribution"
p(x)= exp(-(log(x)-zeta)**2/2/sigma**2)/sqrt(2*pi*sigma**2)/x
plot zeta=0.0, sigma=1.0, p(x) title "\\zeta=0, \{/Symbol \163}=1", \
     zeta=1.0, sigma=1.0, p(x) title "\\zeta=1, \{/Symbol \163}=1"

set xrange [0:5]
set yrange [0:2]
set ytics 0.5
set xtics 1
set output outdir . 'rand-pareto.png'
set title "Pareto Distribution"
p(x)= x>b ? a*b**a/x**(a+1) : 0
plot a=1.0, b=1, p(x) title "a=1, b=1", \
     a=3.0, b=2, p(x) title "a=3, b=2"

set xrange [0:5]
set yrange [0:0.7]
set ytics 0.1
set xtics 1
set output outdir . 'rand-rayleigh.png'
set title "Rayleigh Distribution"
p(x)= (x/sigma**2)*exp(-x**2/(2*sigma**2))
plot sigma=1.0, p(x) title "\{/Symbol \163}=1", \
     sigma=2.0, p(x) title "\{/Symbol \163}=2"

set xrange [0:5]
set yrange [0:1.09]
set ytics 0.5
set xtics 1
set output outdir . 'rand-rayleigh-tail.png'
set title "Rayleigh Tail Distribution"
p(x)= x > a ? (x/sigma**2)*exp((a**2 - x**2)/(2*sigma**2)) : 0
plot a=1.0, sigma=1.0, p(x) title "a=1,\{/Symbol \163}=1", \
     a=0.5, sigma=2.0, p(x) title "a=0.5,\{/Symbol \163}=2"

set xrange [-4:4]
set yrange [0:0.5]
set ytics 0.1
set output outdir . 'rand-tdist.png'
set title "Student's t distribution"
p(x)=gamma((v+1.0)/2)/sqrt(pi*v)/gamma(v/2)*(1+(x**2)/v)**-((v+1.0)/2)
plot v=1.0, p(x) title "{/Symbol \156}_1=1", \
     v=5.0, p(x) title "{/Symbol \156}_1=5"

set xrange [-5:5]
set yrange [0:0.55]
set ytics 0.1
set output outdir . 'rand-laplace.png'
set title "Laplace Distribution (Two-sided Exponential)"
p(x)=exp(-abs(x)/a)/2/a
plot a=1.0, p(x) title "a=1", \
     a=2.0, p(x) title "a=2"

set xrange [-5:5]
set yrange [0:0.8]
set ytics 0.2
set output outdir . 'rand-exppow.png'
set title "Exponential Power Distribution"
p(x)=exp(-(abs(x/a))**b)/2/a/gamma(1.0+1.0/b)
plot a=1.0, b=2.5, p(x) title "a=1, b=2.5", \
     a=1.0, b=0.5, p(x) title "a=1, b=0.5"

set xrange [-5:10]
set yrange [0:0.2]
set ytics 0.1
set output outdir . 'rand-landau.png'
set title "Landau Distribution"
plot 'landau.dat' notitle w lines

set xrange [-5:5]
set yrange [0:0.45]
set ytics 0.1
set output outdir . 'rand-levy.png'
set title "Levy Distribution"
p1(x)=1/(pi*mu*(1+(x/mu)**2))
p2(x)=1/sqrt(2*pi*2*mu**2)*exp(-x**2/(4*mu**2)) 
plot mu=1.0, a=1, p1(x) title "c=1, {/Symbol \141}=1.0", \
     mu=1.0, a=2, p2(x) title "c=1, {/Symbol \141}=2.0"

set xrange [-5:5]
set yrange [0:0.35]
set ytics 0.05
set output outdir . 'rand-levyskew.png'
set title "Levy Skew Distribution"
logp(x)= -1.34229+x*(-0.354314+x*(-0.322538+x*(0.205603+x*(-0.0518879+x*(0.00569502+x*-0.000224843)))))
p1(x)=exp(logp(x))
plot mu=1.0, a=1, p1(x) title "c=1, {/Symbol \141}=1.0, {/Symbol \142}=1.0"

set xrange [0:2]
set yrange [0:1.5]
set ytics 0.5
set xtics 0.5
set output outdir . 'rand-weibull.png'
set title "Weibull Distribution"
p(x)=(b/a) * (x/a)**(b-1) * exp(-(x/a)**b)
plot a=1.0, b=1.0, p(x) title "a=1,b=1", \
     a=1.0, b=2.0, p(x) title "a=1,b=2", \
     a=2.0, b=3.0, p(x) title "a=2,b=3"

set xrange [-2:5]
set yrange [0:0.5]
set ytics 0.1
set xtics 1.0
set output outdir . 'rand-gumbel1.png'
set title "Type 1 Gumbel Distribution"
p1(x)=a*b*exp(-(b*exp(-a*x)+a*x))
plot a=1.0, b=1.0, p1(x) title "Type 1, a=1,b=1"

set xrange [0:2]
set yrange [0:0.7]
set ytics 0.1
set xtics 0.5
set output outdir . 'rand-gumbel2.png'
set title "Type 2 Gumbel Distribution"
p2(x)=x > 0 ? a*b*x**(-a-1)*exp(-b*x**-a) : 0
plot a=1.0, b=1.0, p2(x) title "Type 2, a=1,b=1"

# Discrete distributions

set xlabel "k"
set ylabel "p(k)"
#set ticscale 0.5 1
set mxtics 2

set xrange [-0.5:10.5]
set yrange [0:0.3]
set ytics 0.1
set xtics 1
#set function style step
set output outdir . 'rand-poisson.png'
set title "Poisson Distribution"
p(x)=mu**int(x)/(int(x)!) * exp(-mu)
plot mu=2.5, p(x+0.5) title "{/Symbol \155}=2.5"

set xrange [:1.5]
set yrange [0:1]
set ytics 0.5
set xtics 1
#set function style step
set output outdir . 'rand-bernoulli.png'
set title "Bernoulli Trial"
p(x)= (int(x) == 0) ? 1-p : p
plot p = 0.7, p(x+0.5) title "p=0.7"

set xrange [:10.5]
set yrange [0:0.3]
set xtics 1
set ytics 0.1
set output outdir . 'rand-binomial.png'
set title "Binomial Distribution"
p(x)= P**int(x)*(1-P)**(n-int(x))*gamma(n+1.0)/gamma(int(x)+1.0)/gamma(n-int(x)+1.0) + 1e-5
plot P=0.5,n=9.99999999, p(x+0.5) title "p=0.5,n=9"

set xrange [:5.5]
set yrange [0:0.7]
set ytics 0.1
set xtics 1
set output outdir . 'rand-geometric.png'
set title "Geometric Distribution"
p(x)=int(x) ? P*(1-P)**int(x-1) : 0
plot P=0.5, p(x+0.5) title "p=0.5"

set xrange [:10.5]
set yrange [0:0.7]
set ytics 0.1
set xtics 1
set output outdir . 'rand-logarithmic.png'
set title "Logarithmic Distribution"
p(x)=int(x) ? (-1/log(1-P))*(P**int(x))/int(x) : 0
plot P=0.7, p(x+0.5) title "p=0.7"

set xrange [:10.5]
set yrange [0:0.7]
set ytics 0.1
set xtics 1
set output outdir . 'rand-hypergeometric.png'
set title "Hypergeometric Distribution"
choose(a,b)=gamma(a+1)/(gamma(b+1)*gamma(a-b+1))
p(x)=choose(n1,int(x))*choose(n2,t-int(x))/choose(n1+n2,t)
plot n1=5, n2=20, t=3, p(x+0.5) title "n1=5, n2=20, t=3"

set xrange [:10.5]
set yrange [0:0.3]
set xtics 1
set ytics 0.1
set output outdir . 'rand-nbinomial.png'
set title "Negative Binomial Distribution"
p(x)= (P**n)*((1-P)**(int(x)))*gamma(n+int(x))/gamma(n)/gamma(int(x)+1.0) + 1e-5
plot P=0.5,n=3.5, p(x+0.5) title "p=0.5,n=3.5"

set xrange [:10.5]
set yrange [0:0.3]
set xtics 1
set ytics 0.1
set output outdir . 'rand-pascal.png'
set title "Pascal Distribution"
p(x)= (P**n)*((1-P)**(int(x)))*gamma(n+int(x))/gamma(n)/gamma(int(x)+1.0) + 1e-5
plot P=0.5,n=3, p(x+0.5) title "p=0.5,n=3"

######################################################################

#set ticscale 1 0
set xrange [-5:5]
set yrange [-5:5]
set xtics 1
set ytics 1
#set size 0.8,1.143
set size square
set output outdir . "random-walk.png"
set title "Random walks"
set xzeroaxis
set yzeroaxis
set nokey
set noxlabel
set noylabel
plot "rand-walk.dat" using 1:2 with linesp


