#version 130

in vec3 position;

void main(){
    gl_Position = vec4(position, 4.0);
}
