
precision mediump float; // required in GLSL 100
uniform     vec3 lightDirection;
uniform     vec3 diffuseLightIntensity;
varying vec4 fragmentColor; // this is interpolated across vertices
varying vec4 transformedVertexNormal;

void main()
{
    vec3 inverseLightDirection = normalize(lightDirection);
    float normalDotLight = max(0.0, dot(transformedVertexNormal.xyz, inverseLightDirection));
    gl_FragColor.xyz = normalDotLight * fragmentColor.xyz * diffuseLightIntensity;
    vec3 ambientLightIntensity = vec3(0.3, 0.3, 0.3);
    vec3 vertexAmbientReflectionConstant = fragmentColor.xyz;
    gl_FragColor.xyz += vertexAmbientReflectionConstant * ambientLightIntensity;
    /* Make sure the fragment colour is between 0 and 1. */
    clamp(gl_FragColor, 0.0, 1.0);
}
