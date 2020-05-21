def number_of_leap_years(y):
	return 97*(y//400) + (24*((y-400*(y//400))//100) + ((y-400*(y//400)) - 100*((y-400*(y//400))//100))//4)


def is_leapyear(y):
	if y%400 == 0 or y%100 != 0 and y%4 == 0:
		return True
	else: return False


def delta_days(y, m):
	is_leap_year = 0
	if is_leapyear(y): is_leap_year = 1
	if m == 1: return 0
	if m == 2: return 1
	if m == 3: return is_leap_year -1
	if m == 4 or m == 5: return is_leap_year
	if m == 6 or m == 7: return is_leap_year + 1
	if m == 8: return is_leap_year + 2
	if m == 9 or m == 10: return is_leap_year + 3
	if m == 11 or m == 12: return is_leap_year + 4


def numberOfDays_upto_date(y, m, d):
	return 365*(y-1) + number_of_leap_years(y-1) + 30*(m-1) + delta_days(y, m) + d


def week_day(y, m, d):
	return numberOfDays_upto_date(y, m, d) % 7


def week_day_name(y, m, d):	
	n = week_day(y, m, d)
	if n == 0: return "Sunday"
	if n == 1: return "Monday"
	if n == 2: return "Tuesday"
	if n == 3: return "Wednesday"
	if n == 4: return "Thursday"
	if n == 5: return "Friday"
	if n == 6: return "Saturday"


def format_date(y, m, d): # DD MM, YYYY
	M = {
	            1: "January",
	            2: "February",
	            3: "March",
	            4: "April",
	            5: "May",
	            6: "June",
	            7: "July",
	            8: "August",
	            9: "September",
	            10: "October",
	            11: "November",
	            12: "December"
            }
	return str(d)+' '+M[m]+', '+str(y)
