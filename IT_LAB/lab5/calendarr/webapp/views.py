from django.shortcuts import render
from datetime import date
import calendar
from calendar import HTMLCalendar


def index(request, year, month):
    year = int(year)
    month = int(month)
    if year < 1900 or year > 2099:
        year = date.today().year
    month_name = calendar.month_name[month]
    title = "MyClub Event Calendar - %s %s" % (month_name, year)
    cal = HTMLCalendar().formatmonth(year, month)
    return render(request, 'base.html', {'title': title, 'cal': cal})


def calculate(request):
    return render(request, 'cal.html')


def marks(request):
    return render(request, 'marks.html')


def emp(request):
    return render(request, 'employee.html')


def mag(request):
    return render(request, 'magazine.html')


def cap(request):
    return render(request, 'captcha.html')


def book(request):
    return render(request, 'book.html')
