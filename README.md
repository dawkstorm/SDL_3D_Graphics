
## 3D Graphics in C++ without OpenGL and other 3D APIs

- **Building and running**
	- Run ```git clone https://github.com/dawkstorm/SDL_3D_Graphics.git```
	- Create a build folder in the project
  	- Run ```cmake {path to the CMakeLists.txt}```
	- Run ``` make ```
	- Run in ```graphics3D``` in ```/build```
- **Key features**
	- Program is able to render 3d objects based on verticies input (right now there's only a cube and pyramid)
	- Perform various transformations on 3d objects, such as movement, rotating, scaling and so on
	- Move camera, change its FOV and switch from perspective to orthographic projection and back (although right now only in code)
	- Back face culling is introduced
- **Technical stuff**
	- SDL2 library was used to create a window and draw on it
	- GLM for performing linear algebra operations 
	- Use of matrices for transformations 
	- Use cross product and dot product for back culling
- **Further possible improvements**
	- Add lighting system
	- Add more primitives
	- Fix problem with drawing triangles when passing in along objects
