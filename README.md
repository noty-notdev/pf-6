
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
EL repositorio utilica **CMake** para facilitar la compilación de proyecto,
por lo que una vez clonado el repositorio se deberá iniciar la configuración
del proyecto mediante el siguiente comando:
```bash
cmake -B build
```

Una vez puestas en marcha las configuraciones, solo es cuestión de compilar el proyecto
mediante **CMake**:
```bash
cmake --build build
```

Para probar la ejecución de los *tests* generales se utiliza **ctest**, programa
que viene instalado junto con **CMake** para las pruebas unitarias.
Esto se realiza con el comando:
```bash
ctest -test-dir build -V
```

También puede probar por su cuenta el test especial (`inTest`) que codifica una cadena
dada por el usuario mediante el teclado. La misma se crea en la raíz del directorio
en del repositorio clonado, por lo que lo puede ejecutar así:
```bash
./inTest
```
o bien, si lo ejecuta desde windows
```bash
inTest.exe
```

Si en algún momento desea limpiar los archivos intermedios y de compilación
generados por **CMake** (ejecutables, librerías, objetos, etc.),
solo ejecute el siguiente comando:
```bash
cmake --build build --target clean
```

---

## Contexto del algoritmo.
Yaek.

## Teoría
Beto.
Pon tus fuentes en "referencias", por fa.

---

## Resultados
Mediante la compresión Huffman, podemos obtener distintos resultados,
cada uno correspondiente a una etapa distinta de la ejecución.

Tomemos un ejemplo simple para el análisis y demostración de los resultados
con la cadena `"aaaaaaaaXaaaaaaaa0aaaaaaaa&"`.

### Tabla de códigos

| Símbolo | Frecuencia | código |
| :---: | :---: | :---: |
| `'a'` | 24 | `1`   |
| `'X'` |  1 | `01`  |
| `'0'` |  1 | `00`  |
| `'&'` |  1 | `010` |

### Bits totales

| Bits originales | Bits al comprimir |
| :---: | :---: |
| 216 | 32 |

---

## Análisis de los resultados
Alberto :p

---

## Conclusiones
Alberto :p

---

## Referencias
- Referencia 1.
- ...

