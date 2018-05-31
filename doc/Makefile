documents := pumpcommunication.md
targets := $(patsubst %.md,%.pdf, $(documents))

MDCOMPILER = pandoc
flags = --number-sections --table-of-contents
output_folder = generated

all: $(documents) $(targets)

$(targets): %.pdf:%.md
	mkdir -p generated
	$(MDCOMPILER) -o $(output_folder)/$@ $(flags) $<

clean:
	@rm -rf generated

.PHONY: clean
