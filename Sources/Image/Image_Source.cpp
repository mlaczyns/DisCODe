/*!
 * \file Source_Image.cpp
 * \brief Class responsible for retrieving images from files - methods definition.
 * \author tkornuta
 * \date 2009-11-05
 */

#include <iostream>

#include "Image_Source.hpp"

namespace Sources {
namespace Image {

Image_Source::Image_Source(const std::string & name) : Base::Component(name) {
	LOG(TRACE) << "Hello Image_Source from dl\n";
}

Image_Source::~Image_Source() {
	LOG(TRACE) << "Goodbye Image_Source from dl\n";
}

bool Image_Source::onInit() {
	LOG(TRACE) << "Image_Source::initialize\n";
	newImage = registerEvent("newImage");

	registerStream("out_delay", &out_delay);

	return true;
}

bool Image_Source::onFinish() {
	LOG(TRACE) << "Image_Source::finish\n";

	return true;
}

bool Image_Source::onStep() {
	int del = rand()%20 * 100;
	LOG(TRACE) << "Image_Source::step -> del = " << del << "\n";
	out_delay.write(del);
	newImage->raise();
	return true;
}

bool Image_Source::onStart() {
	return true;
}

bool Image_Source::onStop() {
	return true;
}


}//: namespace Image
}//: namespace Sources
