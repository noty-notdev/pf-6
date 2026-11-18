
# Compresión Huffman

El equipo **Alfa buena maravilla onda dinamita escuadrón lobo**
orgullosamente les presenta este repositorio que contiene el código
relativo a la aplicación de nuestro proyecto final.

## Integrantes del equipo
- 322261077 - Gómez Reyes Álvaro Adrián.
- 323197995 - González Alba Carlos Alberto.
- 323275363 - Granados Hernández Rodrigo Alfredo.
- 319265299 - Martínez Cruz Yaek Alejandro.

---

## Manual de Usuario
Yo me encargo.

---

## Contexto del algoritmo.
Yaek.

## Teoría
El **algoritmo de Huffman** es un método matemático diseñado para **comprimir datos** sin perder ni un solo detalle. 

### 1. Contar frecuencias
Primero, el algoritmo analiza todo el texto y cuenta cuántas veces aparece cada carácter:
* **A:** 5 veces
* **R:** 2 veces
* **B:** 2 veces
* **C:** 1 vez
* **D:** 1 vez

### 2. Construir el "Árbol de Huffman"
El algoritmo organiza los datos creando una estructura de árbol binario de abajo hacia arriba:
* Se toman los dos símbolos con **menor frecuencia** (en este caso, **C** y **D**, ambos con frecuencia 1) y se unen en
  un nuevo "nodo padre" cuya frecuencia es la suma de ambos ($1 + 1 = 2$).
* Se repite este proceso continuamente: siempre se buscan los dos elementos (letras o nodos ya agrupados) con las
  frecuencias más bajas y se combinan.
* Al finalizar, se obtiene un **único árbol binario** donde todos los caracteres originales quedan ubicados en las
  puntas finales (llamadas *hojas*).

### 3. Asignar códigos binarios (ceros y unos)
Una vez construido el árbol, se recorre desde la *raíz* hasta cada letra:
* Cada vez que el camino baja hacia la **izquierda**, se anota un `0`.
* Cada vez que el camino baja hacia la **derecha**, se anota un `1`.
* Gracias a la forma en que se construyó el árbol, las letras más frecuentes (como la **A**) quedan muy cerca de la
  cima, obteniendo códigos muy cortos. Las letras raras quedan en los niveles más profundos, recibiendo códigos más
  largos.

### 4. Generar el resultado comprimido
En sistemas tradicionales (como el estándar ASCII), cada letra ocupa exactamente **8 bits**, sin importar si es muy
común o muy rara. Con Huffman, se asignan longitudes variables:
* **A** = `0` *(1 bit)*
* **B** = `10` *(2 bits)*
* **R** = `110` *(3 bits)*
* **C** = `1110` *(4 bits)*
* **D** = `1111` *(4 bits)*

---

## Resultados
---

## Referencias

- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to algorithms (4.ª ed.). The MIT
  Press.
  
- Huffman, D. A. (1952). A method for the construction of minimum-redundancy codes. Proceedings of the IRE, 40(9), 1098
  1101. https://doi.org/10.1109/JRPROC.1952.273898
  
- ...

