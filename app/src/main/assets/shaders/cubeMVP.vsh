
attribute   vec3 vertexPosition;
attribute   vec4 vertexColor;
attribute   vec3 vertexNormal;

varying     vec4 fragmentColor;     // this is 'sent' to the fragment shader
varying     vec4 transformedVertexNormal;
uniform     mat4 mvpMat;

void main() {
    gl_Position     = mvpMat * vec4(vertexPosition, 1.0);
    transformedVertexNormal = normalize((mvpMat * vec4(vertexNormal, 0.0)).xyzw);
    fragmentColor   = vertexColor;
}
