# 🌌 3D Space Station & Solar System Simulation

<p align="center">
  <b>An Interactive 3D Solar System & Space Station Simulation built with C++, OpenGL and GLUT</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C++-OpenGL-blue?style=for-the-badge&logo=cplusplus">
  <img src="https://img.shields.io/badge/Graphics-OpenGL-green?style=for-the-badge&logo=opengl">
  <img src="https://img.shields.io/badge/Library-GLUT-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Platform-Windows-lightgrey?style=for-the-badge&logo=windows">
</p>

---

## 🚀 About the Project

**3D Space Station & Solar System Simulation** is an interactive computer graphics project developed using **C++, OpenGL, and GLUT**.

The project presents an animated 3D space environment containing the **Sun, Earth, Moon, Mars, Saturn, asteroid belt, satellite, and an ISS-style space station**.

It demonstrates fundamental and advanced computer graphics concepts including **3D transformations, hierarchical modeling, orbital animation, perspective projection, lighting, depth testing, camera movement, and real-time interaction**.

---

## ✨ Features

- ☀️ 3D animated Sun
- 🌍 Earth orbiting around the Sun
- 🌙 Moon orbiting around Earth
- 🔴 Animated Mars
- 🪐 Saturn with a 3D planetary ring
- ☄️ Asteroid belt
- 🛰️ Artificial satellite orbiting Earth
- 🛸 ISS-style space station
- 🌠 Animated shooting star
- ⭐ Space star field
- 💡 Dynamic OpenGL lighting
- 🔄 Planet self-rotation
- 🌀 Hierarchical orbital animation
- 🎥 Multiple camera views
- 🎮 Interactive keyboard controls
- ⏯️ Pause and resume simulation
- 🖥️ Full-screen rendering
- 📐 Perspective projection
- 🔲 Depth-buffered 3D rendering

---

## 🎥 Project Preview

### Main Solar System View

> Add your project screenshot here.

```markdown
![Solar System](screenshots/solar-system.png)
```

### Earth & Space Station

```markdown
![Space Station](screenshots/space-station.png)
```

### Saturn & Asteroid Belt

```markdown
![Saturn](screenshots/saturn.png)
```

---

## 🎬 Demo Video

A demonstration video can be added here:

```markdown
[▶ Watch Project Demo](YOUR_VIDEO_LINK_HERE)
```

You can use a **YouTube video link** or upload a demonstration video to GitHub and place its link here.

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move Camera Forward |
| `S` | Move Camera Backward |
| `A` | Move Camera Left |
| `D` | Move Camera Right |
| `↑` | Move Camera Up |
| `↓` | Move Camera Down |
| `←` | Move Camera Left |
| `→` | Move Camera Right |
| `1` | Main Camera View |
| `2` | Top Camera View |
| `3` | Side Camera View |
| `R` | Reset Camera |
| `SPACE` | Pause / Resume Animation |
| `ESC` | Exit Simulation |

---

## 🪐 Simulation Structure

```text
                         Moon
                          │
                          ▼
                   ┌─────────────┐
                   │    Earth    │
                   └─────────────┘
                      │       │
                Satellite   Space Station
                      │
                      ▼
                     SUN
                  /   |    \
             Earth   Mars   Saturn
                       │
                 Asteroid Belt
```

The simulation uses **hierarchical transformations** so that objects can maintain their own rotation while simultaneously orbiting another object.

For example:

```text
Sun
 └── Earth Orbit
      ├── Earth Rotation
      ├── Moon Orbit
      │    └── Moon Rotation
      ├── Satellite Orbit
      └── Space Station Orbit
```

---

## 🛠️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Core programming language |
| OpenGL | 3D graphics rendering |
| GLUT | Window management and input handling |
| GLU | Perspective and camera utilities |
| Code::Blocks | Development environment |
| MinGW | C++ compiler |

---

## 🧠 Computer Graphics Concepts

This project demonstrates several important Computer Graphics concepts:

### 1. Translation

`glTranslatef()` is used to position planets, satellites and other objects in the 3D environment.

### 2. Rotation

`glRotatef()` controls planetary rotation and orbital movement.

### 3. Scaling

`glScalef()` is used to create differently sized 3D components.

### 4. Hierarchical Modeling

`glPushMatrix()` and `glPopMatrix()` isolate transformations and allow objects such as the Moon, satellite and space station to move relative to Earth.

### 5. Perspective Projection

`gluPerspective()` creates a realistic 3D perspective.

### 6. Camera

`gluLookAt()` provides an interactive camera system with multiple viewpoints.

### 7. Lighting

OpenGL lighting and material properties provide depth and illumination to the 3D objects.

### 8. Animation

`glutTimerFunc()` continuously updates orbital positions and object rotations.

---

## 📂 Project Structure

```text
3D-Space-Station-Solar-System-Simulation/
│
├── main.cpp
│
├── 3D Space Station & Solar System Simulation.cbp
├── README.md
│
├── screenshots/
│   ├── solar-system.png
│   ├── space-station.png
│   └── saturn.png
│
└── .gitignore
```

---

## ⚙️ How to Run

### Requirements

Make sure you have:

- C++ Compiler
- OpenGL
- GLUT / FreeGLUT
- Code::Blocks or another compatible C++ IDE

### Using Code::Blocks

1. Clone this repository:

```bash
git clone https://github.com/Tashin90/3D-Space-Station-Solar-System-Simulation.git
```

2. Open:

```text
3D Space Station & Solar System Simulation.cbp
```

3. Make sure the required OpenGL/GLUT libraries are configured.

4. Build the project.

5. Run the application.

---

## 🔗 Required Libraries

The project uses the following OpenGL libraries:

```text
opengl32
glu32
glut32 / freeglut
```

Typical headers:

```cpp
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
```

---

## 🔄 Animation System

The simulation continuously updates the rotation and orbital angles.

```cpp
earthOrbit += 0.30f;
marsOrbit += 0.20f;
saturnOrbit += 0.10f;

moonOrbit += 1.8f;
satelliteOrbit += 2.8f;
stationOrbit += 1.0f;
```

Different orbital speeds create a more dynamic solar-system visualization.

---

## 🎯 Project Objectives

The main objectives of this project are to:

- Understand 3D transformations in OpenGL
- Implement hierarchical object relationships
- Create real-time 3D animations
- Implement orbital and rotational motion
- Apply lighting and material properties
- Implement interactive camera movement
- Develop a complete 3D scenario using OpenGL and GLUT

---

## 🔮 Future Improvements

Possible future improvements include:

- 🌎 Detailed planet textures
- 🌌 Skybox and improved space environment
- ☀️ Enhanced Sun effects
- 🪐 Additional planets
- 🛰️ More detailed ISS model
- 🚀 Animated spacecraft
- 🌑 Planet shadows
- 🎥 Cinematic camera animation
- 🔊 Background audio
- 🖱️ Mouse-controlled camera

---

## 👨‍💻 Author

**MD. Naimul Haque Tashin**

Computer Science  
American International University-Bangladesh (AIUB)

GitHub: [@Tashin90](https://github.com/Tashin90)

---

## ⭐ Support

If you like this project, consider giving the repository a **⭐ Star**.

It helps support the project and future improvements.

---

<p align="center">
  Made with ❤️ using C++, OpenGL & GLUT
</p>
