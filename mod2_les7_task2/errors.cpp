#include "errors.h"

Errors::Errors(std::string textError) {
	this->textError = textError;
};

std::string Errors::text() {
	return "������ �������� ������. �������: " + this->textError;
}