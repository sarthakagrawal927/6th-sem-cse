from django.shortcuts import render, redirect
from .forms import CalculatorForm
from django.contrib import messages

# Create your views here.


def calculator(request):
    form = CalculatorForm()
    if request.method == 'POST':
        form = CalculatorForm(request.POST)
        if form.is_valid():
            number_1 = form.cleaned_data.get('number_1')
            number_2 = form.cleaned_data.get('number_2')
            operation = form.cleaned_data.get('operation')
            result = eval(str(number_1)+operation+str(number_2))
            messages.success(request, f'result of operation is {result}')
            return redirect('calculator')
    context = {
        'form': form
    }
    return render(request, 'calculator/index.html', context)
