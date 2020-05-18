# 3uzd_Vector
## 5 skirtingų funkcijų pavyzdžiai
```
void push_back(const T& val)
    {
        if (avail == limit)
        {
            grow();
        }
        unchecked_append(val);
    }
```
## Spartos analizė
#### Efektyvumo/spartos analizė naudojant originalų std::vector ir sukurtą mano vector. Lyginama, kiek laiko užtrunka  std::vector tipo ir mano vector tipo tuščių vektorių užpildymas, naudojant push_back() funkciją:

|  Konteineris       | 10000 | 100000 | 1000000 | 10000000 | 100000000 |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- 
| std::vector  | 0.000998s | 0.007976s |  0.070767s | 0.428178s | 2.658888s | 
| mano vector | 0.001052s | 0.006993s | 0.039895s | 0.263296s | 2.180171s |


#### Konteinerių (mano vector ir std::vector) atminties perskirstymai užpildant 100000000 elementų. Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: capacity() == size():

| Konteineris | Perskirstymai |
| ------------- | ------------- |  
| std::vector  | 27| 
| mano vector | 27 |

#### Spartos analizė naudojant duomenų failą su 100000 studentų įrašų, lyginant kiek laiko užtrunka programos veikimas naudojant std::vector ir mano vector realizacijas:

| Konteineris | 100000 | 
| ------------- | ------------- | 
| std::vector  |4.2063s| 
| mano vector | 6.14874s|


