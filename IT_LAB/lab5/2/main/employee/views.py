from django.shortcuts import render, redirect
from .forms import EmployeeForm
from django.contrib import messages
from datetime import date


def employee(request):
    form = EmployeeForm()
    if request.method == 'POST':
        form = EmployeeForm(request.POST)
        if form.is_valid():
            employee_id = form.cleaned_data.get('employee_id')
            date_of_joining = form.cleaned_data.get('date_of_joining')
            result = date.today().year - date_of_joining.year
            if result > 5:
                messages.warning(request, f'{employee_id}, you are not eligible for promotion')
            else:
                messages.success(request, f'{employee_id}, you are eligible for promotion')
            return redirect('employee')
    context = {
        'form': form
    }
    return render(request, 'employee/index.html', context)
