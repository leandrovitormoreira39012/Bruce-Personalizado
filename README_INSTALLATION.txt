Firmware Ambientes - instalação e uso
------------------------------------

Conteúdo do ZIP:
- boards/ambiente-01/
- boards/ambiente-02/
- boards/ambiente-03/
- boards/ambiente-04/
- lib/TFT_eSPI/User_Setups/Setup_ambiente*.h

Como usar dentro do repositório BruceDevices/firmware:
1) Copie as pastas 'boards' e 'lib' para a raiz do seu repositório (ou faça merge). 
   Exemplo:
     cp -r firmware-ambientes/boards ./boards
     cp -r firmware-ambientes/lib/TFT_eSPI/User_Setups ./lib/TFT_eSPI/User_Setups

2) Habilitar o User_Setup que deseja:
   - Abra o arquivo lib/TFT_eSPI/User_Setup.h (no repositório) e inclua o arquivo gerado. Por exemplo, para Ambiente-02:
       #include <User_Setups/Setup_ambiente02_ST7789.h>
     Ou simplesmente copie o conteúdo do Setup_ambienteXX para o User_Setup.h atual.
   - Alternativamente, mantenha vários arquivos em User_Setups e altere a inclusão conforme o ambiente.

3) Build:
   - No diretório raiz do firmware (onde está platformio.ini principal), você pode compilar um ambiente com:
       pio run -e ambiente-01
     ou adicione os envs ao default_envs no platformio.ini principal.

Notas sobre drivers de vídeo (onde incluir alterações):
- Adicione/edite arquivos em: lib/TFT_eSPI/User_Setups/
  - Por convenção a biblioteca TFT_eSPI carrega um único Setup (você precisa incluí-lo em lib/TFT_eSPI/User_Setup.h).
  - Eu gerei:
    * Setup_ambiente01_ST7735.h
    * Setup_ambiente02_ST7789.h
    * Setup_ambiente04_ST7789_no_cs.h
  - Para ativar um deles, edite lib/TFT_eSPI/User_Setup.h e inclua a linha:
       #include <User_Setups/Setup_ambiente02_ST7789.h>
    (substitua pelo setup desejado)
- Se preferir alternar dinamicamente entre setups, substitua o User_Setup.h antes de compilar (script, etc).

ADDED Annotations:
- Todos os arquivos criados contém comentários com "ADDED" indicando que são adições/alterações sugeridas.
