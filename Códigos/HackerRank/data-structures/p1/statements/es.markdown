# Left - Rigth Rotation

Una operación de rotación de derecha o izquierda sobre un array de longitud **N** desplaza el array 1 unidad a la derecha o izquierda correspondientemente. Por ejemplo, si dos operaciones de rotación a la izquierda son hechas sobre el array [1, 2, 3, 4, 5] es modificado como sigue [3, 4, 5, 1, 2]

Dado un array de longitud **N** y un número de rotaciones imprime el array resultante en una sola linea separado con espacios.

## Formato de entrada

La primer linea contiene dos enteros **N** y **D** separados por un espacio denotando la longitud del array y el número de rotaciones a realizar respectivamente. La segunda linea contiene **N** enteros separados por espacios representado el array, por la tercera linea contiene **D** número enteros **R** representado el número de rotaciones a hacer, $$R_D$$ si es positivo representa las rotaciones a la derecha si $$R_D$$ es negativo representa las rotaciones a la izquierda.

### Restriciones

- $$ 1 <= N <= 10^5 $$


-  $$ 1 <= D <= N $$


- $$ -10^6 <= R_D <= 10^6 $$

## Formato de salida

Imprime una sola linea de enteros separados por espacio el array resultante.

## Ejemplo de entrada

```
5 4
1 2 3 4 5
1 2 -1 -4
```

## Ejemplo de salida

```
3 4 5 1 2
```

