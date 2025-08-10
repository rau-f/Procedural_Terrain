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


void Terrain::genNormals()
{
    for (int i = 0; i < m_Indices.size(); i += 3)
    {
        unsigned int i0 = m_Indices[i + 0];
        unsigned int i1 = m_Indices[i + 1];
        unsigned int i2 = m_Indices[i + 2];

        Vertex &v0 = m_Vertices[i0];
        Vertex &v1 = m_Vertices[i1];
        Vertex &v2 = m_Vertices[i2];

        glm::vec3 edge1 = v1.position - v0.position;
        glm::vec3 edge2 = v2.position - v0.position;
        glm::vec3 faceNormal = glm::normalize(glm::cross(edge1, edge2));

        v0.normal += faceNormal;
        v1.normal += faceNormal;
        v2.normal += faceNormal;
    }

    for (auto& v : m_Vertices)
        v.normal = glm::normalize(v.normal);
}




void Terrain::sendToGPU()
{
    m_VA.Bind();
    m_VB.Bind();
    m_IB.Bind();

    m_VB.setBufferData(m_Vertices, m_Vertices.size() * sizeof(Vertex));
    m_IB.setIndexData(m_Indices, m_Indices.size() * sizeof(unsigned int));

    m_VA.LinkAttrib(0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
    // m_VA.LinkAttrib(1, 3, GL_FLOAT, sizeof(Vertex), (void*) (sizeof(glm::vec3)));
    // m_VA.LinkAttrib(2, 2, GL_FLOAT, sizeof(Vertex), (void*) (sizeof(glm::vec3)));
    m_VA.LinkAttrib(3, 3, GL_FLOAT, sizeof(Vertex), (void*) (sizeof(glm::vec3)));

    m_VB.Unbind();
    m_VA.Unbind();
    m_IB.Unbind();
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




std::vector<Vertex>& Terrain::getVertices()
{
    return m_Vertices;
}


std::vector<unsigned int>& Terrain::getIndices()
{
    return m_Indices;
}
