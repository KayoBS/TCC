# arquivos dos programas principais
mkdir esp32_main_code
mkdir ardun_main_code

# arquivos principais para as suas respectivas pastas
mv code/ardun_main_code.ino ./ardun_main_code/
mv code/esp32_main_code.ino ./esp32_main_code/

# arquivos de software de leitura via hardware (sensores)
mv code/sensitive_layer/acs712/*.* ./ardun_main_code/
mv code/voltage_divider_metrics/*.* ./ardun_main_code/
mv code/voltage_reader/*.* ./ardun_main_code

# tipos de dados e métodos de ordenação
mv code/data_and_algorithms/ordenation_methods/*.* ./ardun_main_code
mv code/data_and_algorithms/consts/consts.h ./ardun_main_code
cp code/data_and_algorithms/tdata/tdata.h ./ardun_main_code #arduino envia
mv code/data_and_algorithms/tdata/tdata.h ./esp32_main_code #esp recebe
