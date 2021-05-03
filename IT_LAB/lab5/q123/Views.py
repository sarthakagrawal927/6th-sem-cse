from django.shortcuts import render


def calculate(request):
    return render(request, 'cal.html')


def marks(request):
    return render(request, 'marks.html')


def emp(request):
    return render(request, 'employee.html')
