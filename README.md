# 3uzd_Vector
## Skirtingų funkcijų pavyzdžiai
#### push_back():
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
#### rbegin():
Grąžina atvirkštinį iterator į pirmąjį atvirkštinio konteinerio elementą. * Tai atitinka paskutinį neapversto konteinerio elementą. * Jei konteineris tuščias, grąžinamas iterator yra lygus rend ().
```
iterator rbegin()
    {
        iterator it = limit;
        return --it;
    }
```
#### reserve():
```
void reserve(size_type new_cap)
    {
        if (new_cap > capacity())
        {
            iterator new_data = alloc.allocate(new_cap);
            iterator new_avail = std::uninitialized_copy(data, avail, new_data);
            uncreate();
            data = new_data;
            avail = new_avail;
            limit = data + new_cap;
        }
    }
```
#### begin():
```
iterator begin() { return data; }
const_iterator begin() const { return data; }
```
#### rend():
```
iterator rend()
    {
        iterator it = data;
        return ++it;
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
| std::vector  |2.2063s| 
| mano vector | 2.14874s|


