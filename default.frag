#version 330 core
out vec4 FragColor;

in vec3 color;

in vec3 Normal;
in vec2 texCoord;
uniform sampler2D tex0;

uniform vec4 lightColor;

uniform vec3 lightPos;
uniform vec3 camPos;
uniform sampler2D tex1;

in vec3 crntPos;

vec4 pointLight() {
   float ambient = 0.3f;
   vec3 lightVec = lightPos - crntPos;
   float dist = length(lightVec);
   float a = 0.2;
   float b = 0.5;
   float inte = 1.0f/(a*dist*dist + b*dist + 1.0f);
   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(lightVec);

   float diffuse = max(dot(normal,lightDirection),0.0f);
   float specularLight = 0.5f;
   vec3 viewDirection = normalize(camPos-crntPos);
   vec3 reflectionDirection = reflect(-lightDirection,normal);
   float specAmount = pow(max(dot(viewDirection,reflectionDirection),0.0f),8);

   float specular = specAmount * specularLight;
   return texture(tex0, texCoord)*lightColor*(diffuse*inte +ambient)+ texture(tex1, texCoord).r *specular*lightColor;
}

vec4 directLight() {
   float ambient = 0.3f;
   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(vec3(-1.0f,-1.0f,-1.0f));

   float diffuse = max(dot(normal,lightDirection),0.0f);
   float specularLight = 0.5f;
   vec3 viewDirection = normalize(camPos-crntPos);
   vec3 reflectionDirection = reflect(-lightDirection,normal);
   float specAmount = pow(max(dot(viewDirection,reflectionDirection),0.0f),8);

   float specular = specAmount * specularLight;
   return texture(tex0, texCoord)*lightColor*(diffuse +ambient)+ texture(tex1, texCoord).r *specular*lightColor;
}

vec4 coinLight() {
   float outerCone = 0.8f;
   float innerCone = 0.9f;
   float ambient = 0.3f;
   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(lightPos - crntPos);

   float diffuse = max(dot(normal,lightDirection),0.0f);
   float specularLight = 0.5f;
   vec3 viewDirection = normalize(camPos-crntPos);
   vec3 reflectionDirection = reflect(-lightDirection,normal);
   float specAmount = pow(max(dot(viewDirection,reflectionDirection),0.0f),8);

   float specular = specAmount * specularLight;
   float angle = dot(vec3(0.0f,-0.1f,0.0f),-lightDirection);
   float inten  = clamp((angle-outerCone)/(innerCone-outerCone),0.0f,1.0f);
   return texture(tex0, texCoord)*lightColor*(diffuse*inten +ambient)+ texture(tex1, texCoord).r *specular*inten*lightColor;
}
void main()
{
   
   FragColor = coinLight();
   

}