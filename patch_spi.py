Import("env")
import os

def patch_spi_cpp(source, target, env):
    framework_dir = env.PioPlatform().get_package_dir("framework-arduinoespressif32")
    if not framework_dir:
        return
    spi_cpp_path = os.path.join(framework_dir, "libraries", "SPI", "src", "SPI.cpp")
    if os.path.exists(spi_cpp_path):
        with open(spi_cpp_path, "r", encoding="utf-8") as f:
            content = f.read()
        
        if "#define SS 5" not in content:
            patch = "#define SS 5\n"
            content = patch + content
            with open(spi_cpp_path, "w", encoding="utf-8") as f:
                f.write(content)
            print("Script aplicado: SPI.cpp ajustado com sucesso!")

env.AddPreAction("buildprog", patch_spi_cpp)

