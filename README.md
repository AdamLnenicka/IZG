This project is implementation of GPU (Graphics Processing Unit) with C. 
Project contains numerous sets of functions and data structures designed to facilitate graphics rendering operations on a GPU. This documentation provides an overview of the functionalities provided by the GPU Implementation and how to use them.
By following the guidelines and examples provided in this documentation, developers can efficiently utilize the GPU for rendering high-quality graphics in their applications.

Certainly! Here's a draft of the documentation for the provided GPU implementation code:

---

## Functions

### Vertex Puller Operations
- `cpu_setIndexing`: Sets the indexing for vertex data in a Vertex Puller.
- `cpu_enableVertexPullerHead`: Enables a specific vertex attribute in a Vertex Puller.
- `cpu_disableVertexPullerHead`: Disables a specific vertex attribute in a Vertex Puller.
- `cpu_bindVertexPuller`: Binds a Vertex Puller for subsequent rendering operations.

### GPU Program Operations
- `cpu_createProgram`: Creates a new GPU program.
- `cpu_deleteProgram`: Deletes a GPU program.
- `cpu_attachVertexShader`: Attaches a vertex shader to a GPU program.
- `cpu_attachFragmentShader`: Attaches a fragment shader to a GPU program.
- `cpu_useProgram`: Specifies which GPU program should be used for rendering.

### Rendering Operations
- `cpu_clearColor` and `cpu_clearDepth`: Clears the color and depth buffers, respectively.
- `cpu_getColor` and `gpu_getDepth`: Retrieves the color and depth values at a specific pixel location, respectively.
- `gpu_setDepth` and `gpu_setColor`: Sets the depth and color values at a specific pixel location, respectively.
- `cpu_setViewportSize`: Sets the viewport size for rendering.

### Shader Interpretation
- Functions for interpreting vertex and fragment shader inputs and outputs as different types (`float`, `Vec2`, `Vec3`, `Vec4`).

## Usage
1. Initialize the GPU and create Vertex Pullers, GPU programs, and shaders as needed.
2. Set up vertex data, indexing, and vertex attributes using the provided functions.
3. Bind the appropriate Vertex Puller and GPU program for rendering.
4. Clear the color and depth buffers if necessary.
5. Render geometry by specifying draw calls and issuing rendering commands.
6. Retrieve rendered results as needed.

## Error Handling
- Functions assert GPU validity and handle invalid inputs gracefully.
- Error messages are printed to standard error for debugging purposes.

## Example
```cpp
// Example code snippet demonstrating the usage of the GPU Implementation

#include <gpu.h>

int main() {
    // Initialize GPU
    GPU gpu = initialize_gpu();

    // Create a Vertex Puller
    VertexPullerID puller = create_vertex_puller(gpu);

    // Enable vertex attributes
    enable_vertex_attribute(gpu, puller, ATTRIBUTE_POSITION);
    enable_vertex_attribute(gpu, puller, ATTRIBUTE_NORMAL);

    // Create a GPU program
    ProgramID program = create_program(gpu);

    // Attach vertex and fragment shaders
    attach_vertex_shader(gpu, program, VERTEX_SHADER);
    attach_fragment_shader(gpu, program, FRAGMENT_SHADER);

    // Use the GPU program for rendering
    use_program(gpu, program);

    // Set viewport size
    set_viewport_size(gpu, 800, 600);

    // Clear color and depth buffers
    clear_color(gpu, {0.0f, 0.0f, 0.0f, 1.0f});
    clear_depth(gpu, 1.0f);

    // Render geometry
    render_geometry(gpu, puller);

    // Retrieve rendered results
    // ...

    // Cleanup
    delete_program(gpu, program);
    destroy_vertex_puller(gpu, puller);
    shutdown_gpu(gpu);

    return 0;
}
```


<h2> main.c file</h2>

### Purpose
This file serves as the main entry point for the application. It is responsible for initializing the SDL2 library, creating a window for graphics output, handling user events, and managing the rendering of different scenes using various methods.

## Functionality

1. **Command Line Arguments Handling**
   - The program checks for command line arguments, specifically `-c` for conformance tests and `-p` for performance tests.
   - If the `-c` flag is provided, the program runs conformance tests comparing rendered output to a reference image.
   - If the `-p` flag is provided, the program executes performance tests.

2. **SDL2 Initialization**
   - Initializes the SDL2 library for video rendering.

3. **Window and Surface Creation**
   - Creates a window for rendering with specified dimensions.
   - Obtains a surface for drawing graphics within the window.

4. **Renderer Creation**
   - Sets up a software renderer for rendering graphics on the surface.

5. **Scene Initialization and Rendering**
   - Defines pointers to methods responsible for initializing, rendering, and cleaning up various scenes.
   - Allows switching between different rendering methods dynamically.
   - Handles user input events, such as keyboard and mouse interactions, to control scene switching and scene-specific actions.

6. **Main Loop**
   - Enters a main loop where events are processed and scenes are rendered continuously until the user closes the window.

7. **Cleanup**
   - Properly releases all allocated resources upon program termination.

## Usage
- To run the application:
  ```
  ./application_name [options]
  ```

## Options
- `-c <path_to_reference_image>`: Run conformance tests comparing rendered output to a reference image.
- `-p`: Run performance tests.
