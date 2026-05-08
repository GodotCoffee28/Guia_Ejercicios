#include <iostream>
#include <vector>   // Si usas std::vector<std::string>
#include <string>
#include <algorithm> // Para std::sort, etc. si ordenas los argumentos
// Para conversiones de string a números:
#include <stdexcept> // Para manejar excepciones de std::stoi/stod

int main(int argc, const char** argv) {
    if (argc < 2) { // Verificar si hay al menos un argumento además del nombre del programa
        std::cout << "Uso: " << argv[0] << " <comando> [argumentos]" << std::endl;
        std::cout << "Ejemplo: " << argv[0] << " sumar 5 10" << std::endl;
        std::cout << "Ejemplo: " << argv[0] << " archivo mi_texto.txt" << std::endl;
        return 1; // Salir con código de error
    }

    // Convertir el primer argumento (comando) a std::string para facilitar la comparación
    std::string comando = argv[1];

    if (comando == "sumar") {
        if (argc < 4) {
            std::cout << "Uso: " << argv[0] << " sumar <numero1> <numero2>" << std::endl;
            return 1;
        }
        try {
            // Convertir strings a enteros
            int num1 = std::stoi(argv[2]);
            int num2 = std::stoi(argv[3]);
            std::cout << "La suma es: " << num1 + num2 << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Argumentos invalidos para la suma. Se esperaban numeros." << std::endl;
            return 1;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Numeros demasiado grandes para la suma." << std::endl;
            return 1;
        }
    } else if (comando == "saludar") {
        if (argc < 3) {
            std::cout << "Uso: " << argv[0] << " saludar <nombre>" << std::endl;
            return 1;
        }
        std::string nombre = argv[2];
        std::cout << "Hola, " << nombre << "!" << std::endl;
    } else if (comando == "archivo") {
        if (argc < 3) {
            std::cout << "Uso: " << argv[0] << " archivo <nombre_de_archivo>" << std::endl;
            return 1;
        }
        std::string nombreArchivo = argv[2];
        std::cout << "Intentando abrir el archivo: " << nombreArchivo << std::endl;
        // Aquí iría la lógica para abrir y leer/escribir en el archivo
        // (requeriría #include <fstream>)
        // Por ejemplo:
        // std::ifstream archivo(nombreArchivo);
        // if (archivo.is_open()) {
        //     std::cout << "Archivo abierto con exito." << std::endl;
        //     archivo.close();
        // } else {
        //     std::cerr << "No se pudo abrir el archivo." << std::endl;
        // }
    } else {
        std::cout << "Comando desconocido: '" << comando << "'" << std::endl;
        std::cout << "Comandos disponibles: sumar, saludar, archivo" << std::endl;
        return 1;
    }

    return 0; // Salida exitosa
}