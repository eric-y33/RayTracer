#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

// "In graphics, the algebra almost always relates very directly to the geometry."

int main() {
	hittable_list world;

	auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
	auto material_feather_beige = make_shared<lambertian>(color(0.87, 0.65, 0.50));
	auto material_feather_white = make_shared<lambertian>(color(1, 1, 1));
	auto material_feather_green = make_shared<lambertian>(color(0.18, 0.60, 0.37));
	auto material_beak_white = make_shared<metal>(color(1, 1, 1), 1.0);
	auto material_beak_orange = make_shared<metal>(color(0.90, 0.45, 0.28), 0.8);
	auto material_eye_black = make_shared<metal>(color(0.15, 0.15, 0.15), 0.2);
	auto material_eye_white = make_shared<metal>(color(1, 1, 1), 0.2);
	auto material_glass = make_shared<dielectric>(1.50);
	//auto material_left = make_shared<dielectric>(1.50);
	//auto material_bubble = make_shared<dielectric>(1.00 / 1.50);
	//auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

	// Base
	world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
	world.add(make_shared<sphere>(point3(0.0, 0.2, -1.2), 0.6, material_feather_beige));

	// Face
	world.add(make_shared<sphere>(point3(-0.1, 0.2, -0.8), 0.25, material_feather_white));
	world.add(make_shared<sphere>(point3(0.1, 0.2, -0.8), 0.25, material_feather_white));

	// Tie
	world.add(make_shared<sphere>(point3(-0.07, -0.04, -0.905), 0.243, material_feather_green));
	world.add(make_shared<sphere>(point3(0.07, -0.04, -0.905), 0.243, material_feather_green));

	// Bottom
	world.add(make_shared<sphere>(point3(-0.07, -0.11, -0.94), 0.225, material_feather_white));
	world.add(make_shared<sphere>(point3(0.07, -0.11, -0.94), 0.225, material_feather_white));

	// Beak
	world.add(make_shared<sphere>(point3(0.0, 0.17, -0.65), 0.11, material_beak_orange));
	world.add(make_shared<sphere>(point3(0.0, 0.19, -0.65), 0.12, material_beak_white));

	// Eyes
	world.add(make_shared<sphere>(point3(-0.14, 0.18, -0.6), 0.072, material_eye_black));
	world.add(make_shared<sphere>(point3(0.14, 0.18, -0.6), 0.072, material_eye_black));
	world.add(make_shared<sphere>(point3(-0.14, 0.175, -0.55), 0.026, material_eye_white));
	world.add(make_shared<sphere>(point3(0.14, 0.175, -0.55), 0.026, material_eye_white));
	world.add(make_shared<sphere>(point3(-0.145, 0.174, -0.55), 0.06, material_glass));
	world.add(make_shared<sphere>(point3(0.145, 0.174, -0.55), 0.06, material_glass));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 800;
	cam.samples_per_pixel = 50;
	cam.max_depth = 50;

	cam.vfov = 75;
	cam.lookfrom = point3(0.25, -0.05, 0);
	cam.lookat = point3(0, 0.15, -1);
	cam.vup = vec3(0, 1, 0);

	cam.defocus_angle = 0.0;
	cam.focus_dist = 1.0;
	
	cam.render(world);
}