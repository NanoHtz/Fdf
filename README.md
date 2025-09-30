<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/fdf/banner.svg" alt="Fdf banner">
</p>

<p align="center"><i>🗺️ FdF — Visualizador de mapas de alturas en 3D con proyección isométrica/ortográfica usando MiniLibX, algoritmo de Bresenham, zoom, rotaciones y gradientes de color.</i></p>

<p align="center">
    <img src="https://github.com/NanoHtz/Assets/blob/main/fdf/fdf.gif?raw=1"
       alt="Demostración del proyecto FdF" width="800">
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/125.png" alt="fdf nota" height="120">
</p>

---

## Índice
- [Resumen](#resumen)
- [¿Para qué?](#para-que)
- [Explicación](#explicacion)
- [Compilación](#compilacion)
- [Uso](#uso)
- [Salida esperada y pruebas](#salida)

---
<a id="resumen"></a>
## ✅ Resumen del proyecto<br>

**FdF** carga un **mapa de alturas** (`.fdf`) y lo renderiza en una **ventana** usando **MiniLibX**.  
Cada número del fichero representa la altitud (`z`) de un punto en una malla regular; opcionalmente, cada punto puede tener un **color** en hexadecimal (`z,0xRRGGBB`).  
El programa dibuja los **segmentos** entre puntos adyacentes con **Bresenham** y permite **interacción**: zoom, rotación, traslación, escala de alturas, cambiar proyecciones y paletas.

> Este proyecto sigue la **Norma oficial de 42** para estilo en C (Norminette).
> En todos los proyectos de 42, el uso de la gran mayoria de bibliotecas esta prohibido, siendo nuestro propio desarrollo libft el sustituto de las funciones básicas. 
> - Código legible.  
> - Funciones pequeñas (<25 líneas),
> - 4 parámetros por función,
> - Nombres claros en `snake_case` y en inglés.
> - 1 responsabilidad por función.
>  - Variables declaradas al inicio del bloque(maximo 4 por función). 

---

<a id="para-que"></a>
## 🧩 ¿Para qué?

**¿Qué se aprende?**
- **Algoritmos clásicos**: **Bresenham** para líneas, proyección **isométrica** y ortográfica.
- **Transformaciones geométricas**: rotaciones/traslaciones/escalados en 3D.
- **Parsing robusto**: lectura de ficheros `.fdf`, validación y manejo de colores (`0xRRGGBB`).
- **Diseño de engine** sencillo: doble buffer, *repaint* tras eventos, separación de estado y vista.

---

<a id="explicacion"></a>

  <summary><h3>📝 Explicación</h3></summary>

### 🧠 Ideas clave
---

<a id="compilacion"></a>
## 🛠️ Compilación
⬇️ Descarga
```bash
git clone https://github.com/NanoHtz/fdf.git
```
🏗️ Makefile
```bash
make          # compila ./fdf
make clean    # borra .o
make fclean   # borra .o y binarios
make re       # recompila desde cero
```
🧪 Uso
Utiliza el formato ./fdf + ruta al mapa.
<br>
```bash
./fdf maps/42.fdf
```
Tienes los mapas necesarios en maps/
