#!/usr/bin/env python
# Este archivo usa el encoding: utf-8
# Este programa fue realizado por un completo desconocido(Sebastián Valencia).
# Es de dominio público si no se altera su contenido ***NO CAMBIOS
# Es parcialmente explicado en Sedgewick-introduction to programming in Java
# primera edición. A continuación documentación
# 			http://introcs.cs.princeton.edu/java/12types/
# 			http://introcs.cs.princeton.edu/java/12types/LeapYear.java.html
# 			http://introcs.cs.princeton.edu/java/21function/Calendar.java.html
# Esta versión de calendario usa explícitamente algoritmos de año bisiesto
# y dia gregoriano del calendario. Por falta de tiempo, el proceso de impresión
# es un poco sucio así como la impresión, los algoritmos no fueron depurados 
# ni testeados, sólo se probó que estaban correctos. 
# En caso de encontrar algún bug, favor NO REPORTAR al creador, simplemnte 
# desechar el programa. Gracias

# Para correr el programa en consola >> python gregorianCalendar.py,y
# el programa pedirá un añoy un mes en número, el mes no tiene restricción
# asíque si el usuario ingresa 13 no se conoce el resultado, si ingresa como
# mes un número entre 1 y 12, el programa improme el calendario organizado 
# del mes en ese año.
import sys
days_in_month = [0,31,28,31,30,31,30,31,31,30,31,30,31] # Lista que almacena los posibles valores 
														# de los dias de los meses en el calendario
														# greogoriano, se incluye cero para controlar 
														# el flujo de la impresión en consola
# Lista que almacena los meses [0..11] --> ['Enero'ñ...'Diciembre']
months = ["ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"]
# Función encargada de recibir el año
def input_year():
	year = input('Introduzca el año: ')
	return year
# Función encargada de recibir el mes
def input_month():
	month = input('Introduzca el mes: ')
	return month
# Esta función, me dice si cierto año es o no Bisisesto, es decir, el número de días
# en Febrero, el algoritmo se encuentra en: http://en.wikipedia.org/wiki/Leap_year
def bisiesto(year):
    if n % 400 == 0:
        return True
    if n % 100 == 0:
        return False
    if n % 4 == 0:
        return True
    else:
        return False
# Esta función basada en la función 'dayofTheWeek' en Sedgewick/Introduction to programming in Java,
# toma como parámetro una fecha y devuelve el día de la semana en el cuál cayó, si la respuesta es 1
# entonces fue Lunes, si es 2 Martes y así.
		# Ejemplo: Le preguntamos a la función que día fue Febrero 14, 2000
		# Proceso:
		#			y = 2000 - 1 = 1999
		#			x = 1999 + 1999/4 - 1999/100 - 1999/400 = 2483
		#			m = 2 + 12*1 - 2 = 12
		#			d = (14 + 2483 + (31*12)/12) % 7 = 2500 % 7 = 1 --> LUNES
def gregorian_day(M, D, Y):
	y = Y - (14 - M) / 12
	x = y + y/4 - y/100 + y/400
	m = M + 12 * ((14 - M) / 12) - 2
	d = (D + x + (31*m)/12) % 7
	return d
# Función principal, se encarga de llamar las funciones auxiliares para recibir y procesar
# la información.
def main():	
	Year = input_year() # Obtiene el año de entrada
	Month = input_month() # Obtiene el mes de entrada
	if(Month == 2 and bisiesto(Year)): # Es el mes febrero y el año es bisiesto?
									   # de ser así, cambie la matriz de días para
									   # elmismo mes, sino, deje igual
		days_in_month[Month] = 29
	print '\n'
	print '                               ', months[Month-1], Year
	print "     D     L     M     I     J     V     S"
	for i in range(8):
		sys.stdout.write('    _')
	print '\n'
	d = gregorian_day(Month, 1, Year)
	for i in range(d):
		sys.stdout.write('      ')
	for i in range(1,days_in_month[Month]+1):
		sys.stdout.write('%6d' %i)
		if (((i + d) % 7 == 0) or (i == days_in_month[Month])): 
			print '\n'
main() #Llamo a MAIN()