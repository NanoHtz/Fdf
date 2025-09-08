<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/fdf/banner.svg" alt="Philosophers banner">
</p>

<p align="center"><i>🗺️ FdF — Visualizador de mapas de alturas en 3D con proyección isométrica/ortográfica usando MiniLibX, algoritmo de Bresenham, zoom, rotaciones y gradientes de color.</i></p>

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
<details>
  <summary><h3>📝 Explicación</h3></summary>
