#include "include/Terrain.hpp"


float genHeight(float x, float y, PerlinNoise& noise, int octaves = 8, float freqIncrement = 0.3f, float layerDec = 2.0f);


Terrain::Terrain(int height, int width)
    : meshHeight(height), meshWidth(width),  m_Model(glm::mat4(1.0f))
{
    genVertices();
    genIndices();
    genNormals();
}


void Terrain::genVertices()
{
    float colDist = 40.0 / (meshWidth);
    float rowDist = 40.0 / (meshHeight);
    float x = -1.0f, z = -1.0f;

    // vector

    PerlinNoise noise;

    for (int i = 0; i < meshHeight; i++)
    {
        for (int j = 0; j < meshWidth; j++)
        {
            float nx = j * 0.002;
            float ny = i * 0.002;
            float h = genHeight(nx, ny, noise, 12);

            float y = h;

            if (y < 0.4)
                y = 0.4 * heightScale;
            else
                y = h * heightScale;

            m_Vertices.push_back(Vertex{
                glm::vec3(x, y, z),
                glm::vec3(0)
            });

            x += colDist;
        }

        x = -1.0f;
        z += rowDist;
    }
}


void Terrain::genIndices()
{
    for (int row = 0; row < meshHeight - 1; row++)
    {
        for (int col = 0; col < meshWidth - 1; col++)
        {
            int topLeft = row * meshWidth + col;
            int topRight = row * meshWidth + (col + 1);
            int bottomLeft = (row + 1) * meshWidth + col;
            int bottomRight = (row + 1) * meshWidth + (col + 1);

            m_Indices.push_back(topLeft);
            m_Indices.push_back(bottomLeft);
            m_Indices.push_back(topRight);

            m_Indices.push_back(bottomLeft);
            m_Indices.push_back(bottomRight);
            m_Indices.push_back(topRight);
        }
    }
}


void Terrain::render(glm::mat4& view, glm::mat4& projection)
{
    getShader().Bind();

    // getShader().SetUniform1i("u_Texture", 0);
    // std::cout << "Model: " << glm::to_string(m_Model) << std::endl;

    getShader().SetMat4("u_Model", glm::value_ptr(m_Model));
    getShader().SetMat4("u_View",  glm::value_ptr(view));
    getShader().SetMat4("u_Projection", glm::value_ptr(projection));

    getShader().SetVec3("u_LightDir", glm::value_ptr(glm::normalize(glm::vec3(-0.5, -0.4, -0.4))));
    getShader().SetVec3("u_LightColor", glm::value_ptr(glm::normalize(glm::vec3(0.8f, 0.8f, 0.7f))));
    getShader().SetVec3("u_ObjectColor", glm::value_ptr(glm::normalize(glm::vec3(0.6f, 0.8f, 0.8f))));

    Renderer renderer;
    renderer.Draw(getVA(), getIB(), getShader());
}


float genHeight(float x, float y, PerlinNoise& noise, int octaves, float freqIncrement, float layerDec)
{
    float amplitude = 1.0f;
    float frequency = 1.0f;
    float total = 0.0f;
    float maxValue = 0.0f;

    for (int i = 0; i < octaves; i++)
    {
        float noiseValue = noise.noise(x * frequency, y * frequency, 0.0f);
        total += noiseValue * amplitude;

        maxValue += amplitude;
        amplitude *= freqIncrement;
        frequency *= layerDec;
    }

    return total / maxValue;
}
