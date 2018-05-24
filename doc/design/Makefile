input_type = puml
input_files := $(wildcard *.$(input_type))
output_type = png
output_folder = generated
output_files = $(patsubst %.$(input_type), %.$(output_type), $(input_files))

all: $(output_files)

$(output_files): %.$(output_type): %.$(input_type)
	plantuml -t$(output_type) -o $(output_folder) $<
