# Generated by Django 3.2.3 on 2021-05-31 04:32

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('app', '0002_auto_20210530_1646'),
    ]

    operations = [
        migrations.AddField(
            model_name='cuisine',
            name='rating',
            field=models.CharField(default=4, max_length=50),
            preserve_default=False,
        ),
    ]
