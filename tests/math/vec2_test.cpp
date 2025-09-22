#include <gtest/gtest.h>
#include "StarletMath/vec2.hpp"

TEST(Vec2Test, DefaultConstructor) {
	Vec2<int> vi;
	Vec2<float> vf;
	Vec2<double> vd;

	ASSERT_EQ(vi.x, 0); ASSERT_EQ(vi.y, 0);
	ASSERT_FLOAT_EQ(vf.x, 0.0f); ASSERT_FLOAT_EQ(vf.y, 0.0f);
	ASSERT_DOUBLE_EQ(vd.x, 0.0); ASSERT_DOUBLE_EQ(vd.y, 0.0);
}
TEST(Vec2Test, SingleParamConstructor) {
	Vec2<int> vi(5);
	Vec2<float> vf(5.5f);
	Vec2<double> vd(5.5);

	ASSERT_EQ(vi.x, 5); ASSERT_EQ(vi.y, 5);
	ASSERT_FLOAT_EQ(vf.x, 5.5f); ASSERT_FLOAT_EQ(vf.y, 5.5f);
	ASSERT_DOUBLE_EQ(vd.x, 5.5); ASSERT_DOUBLE_EQ(vd.y, 5.5);
}
TEST(Vec2Test, ParameterConstructor) {
	Vec2<int> vi(1, -2);
	Vec2<float> vf(1.5f, -2.5f);
	Vec2<double> vd(1.5, -2.5);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, -2);
	ASSERT_FLOAT_EQ(vf.x, 1.5f); ASSERT_FLOAT_EQ(vf.y, -2.5f);
	ASSERT_DOUBLE_EQ(vd.x, 1.5); ASSERT_DOUBLE_EQ(vd.y, -2.5);
}
TEST(Vec2Test, CopyConstructor) {
	Vec2<int> vInt1(1, 2);
	Vec2<float> vFloat1(1.0f, 2.0f);
	Vec2<double> vDouble1(1.0, 2.0);

	Vec2<int> vInt2(vInt1);
	Vec2<float> vFloat2(vFloat1);
	Vec2<double> vDouble2(vDouble1);

	ASSERT_EQ(vInt2.x, 1); ASSERT_EQ(vInt2.y, 2);
	ASSERT_FLOAT_EQ(vFloat2.x, 1.0f); ASSERT_FLOAT_EQ(vFloat2.y, 2.0f);
	ASSERT_DOUBLE_EQ(vDouble2.x, 1.0); ASSERT_DOUBLE_EQ(vDouble2.y, 2.0);
}
TEST(Vec2Test, Negative) {
	Vec2<int> vi(-1, -2), vi2(-3, -4);
	Vec2<int> vi3 = vi + vi2;
	ASSERT_EQ(vi3.x, -4);
	ASSERT_EQ(vi3.y, -6);

	Vec2<float> vf(-1.5f, -2.5f), vf2(-3.5f, -4.5f);
	Vec2<float> vf3 = vf - vf2;
	ASSERT_FLOAT_EQ(vf3.x, 2.0f);
	ASSERT_FLOAT_EQ(vf3.y, 2.0f);
}

TEST(Vec2Test, Assignment) {
	Vec2<int> vi1(1, 2), vi2;
	Vec2<float> vf1(1.0f, 2.0f), vf2;
	Vec2<double> vd1(1.0, 2.0), vd2;

	vi2 = vi1;
	vf2 = vf1;
	vd2 = vd1;

	ASSERT_EQ(vi2.x, 1);  ASSERT_EQ(vi2.y, 2);
	ASSERT_FLOAT_EQ(vf2.x, 1.0f); ASSERT_FLOAT_EQ(vf2.y, 2.0f);
	ASSERT_DOUBLE_EQ(vd2.x, 1.0); ASSERT_DOUBLE_EQ(vd2.y, 2.0);
}
TEST(Vec2Test, SelfAssignment) {
	Vec2<int> vi(1, 2);
	Vec2<float> vf(1.0f, 2.0f);
	Vec2<double> vd(1.0, 2.0);

	vi = vi;
	vf = vf;
	vd = vd;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0);
}

TEST(Vec2Test, AdditionAndSubtraction) {
	Vec2<int> vi1(1, 2), vi2(3, 4);
	Vec2<float> vf1(1.0f, 2.0f), vf2(3.0f, 4.0f);
	Vec2<double> vd1(1.0, 2.0), vd2(3.0, 4.0);

	Vec2<int> vi3 = vi1 + vi2;
	Vec2<float> vf3 = vf1 + vf2;
	Vec2<double> vd3 = vd1 + vd2;

	ASSERT_EQ(vi3.x, 4); ASSERT_EQ(vi3.y, 6);
	ASSERT_FLOAT_EQ(vf3.x, 4.0f); ASSERT_FLOAT_EQ(vf3.y, 6.0f);
	ASSERT_DOUBLE_EQ(vd3.x, 4.0); ASSERT_DOUBLE_EQ(vd3.y, 6.0);
}

TEST(Vec2Test, MultiplicationAndDivision) {
		Vec2<int> vi(1, 2);
		Vec2<float> vf(1.0f, 2.0f);
		Vec2<double> vd(1.0, 2.0);

		Vec2<int> viResult = vi * 3;
		Vec2<float> vfResult = vf * 3.0f;
		Vec2<double> vdResult = vd * 3.0;

		ASSERT_EQ(viResult.x, 3); ASSERT_EQ(viResult.y, 6);
		ASSERT_FLOAT_EQ(vfResult.x, 3.0f); ASSERT_FLOAT_EQ(vfResult.y, 6.0f);
		ASSERT_DOUBLE_EQ(vdResult.x, 3.0); ASSERT_DOUBLE_EQ(vdResult.y, 6.0);
}

TEST(Vec2Test, Compound) {
	Vec2<int> vi(1, 2);
	Vec2<float> vf(1.0f, 2.0f);
	Vec2<double> vd(1.0, 2.0);

	vi += Vec2<int>(3, 4);
	vf += Vec2<float>(3.0f, 4.0f);
	vd += Vec2<double>(3.0, 4.0);

	ASSERT_EQ(vi.x, 4);	ASSERT_EQ(vi.y, 6);
	ASSERT_FLOAT_EQ(vf.x, 4.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f);
	ASSERT_DOUBLE_EQ(vd.x, 4.0); ASSERT_DOUBLE_EQ(vd.y, 6.0);

	vi -= Vec2<int>(3, 4);
	vf -= Vec2<float>(3.0f, 4.0f);
	vd -= Vec2<double>(3.0, 4.0);

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0);

	vi *= 3;
	vf *= 3.0f;
	vd *= 3.0;

	ASSERT_EQ(vi.x, 3);	ASSERT_EQ(vi.y, 6);
	ASSERT_FLOAT_EQ(vf.x, 3.0f); ASSERT_FLOAT_EQ(vf.y, 6.0f);
	ASSERT_DOUBLE_EQ(vd.x, 3.0); ASSERT_DOUBLE_EQ(vd.y, 6.0);

	vi /= 3;
	vf /= 3.0f;
	vd /= 3.0;

	ASSERT_EQ(vi.x, 1); ASSERT_EQ(vi.y, 2);
	ASSERT_FLOAT_EQ(vf.x, 1.0f); ASSERT_FLOAT_EQ(vf.y, 2.0f);
	ASSERT_DOUBLE_EQ(vd.x, 1.0); ASSERT_DOUBLE_EQ(vd.y, 2.0);
}

TEST(Vec2Test, Comparison) {
	Vec2<int> vi1(1, 2), vi2(1, 2), vi3(3, 4);
	Vec2<float> vf1(1.0f, 2.0f), vf2(1.0f, 2.0f), vf3(3.0f, 4.0f);
	Vec2<double> vd1(1.0, 2.0), vd2(1.0, 2.0), vd3(3.0, 4.0);

	ASSERT_TRUE(vi1 == vi2); ASSERT_FALSE(vi1 == vi3);
	ASSERT_TRUE(vf1 == vf2); ASSERT_FALSE(vf1 == vf3);
	ASSERT_TRUE(vd1 == vd2); ASSERT_FALSE(vd1 == vd3);

	ASSERT_FALSE(vi1 != vi2); ASSERT_TRUE(vi1 != vi3);
	ASSERT_FALSE(vf1 != vf2); ASSERT_TRUE(vf1 != vf3);
	ASSERT_FALSE(vd1 != vd2); ASSERT_TRUE(vd1 != vd3);
}

TEST(Vec2Test, Length) {
	Vec2<int> vi(3, 4);
	Vec2<float> vf(3.0f, 4.0f);
	Vec2<double> vd(3.0, 4.0);

	ASSERT_FLOAT_EQ(vi.length(), 5.0f);
	ASSERT_FLOAT_EQ(vf.length(), 5.0f);
	ASSERT_DOUBLE_EQ(vd.length(), 5.0);
}
TEST(Vec2Test, LengthSquared) {
	Vec2<int> vi(3, 4);
	Vec2<float> vf(3.0f, 4.0f);
	Vec2<double> vd(3.0, 4.0);

	ASSERT_EQ(vi.lengthSquared(), 25);
	ASSERT_FLOAT_EQ(vf.lengthSquared(), 25.0f);
	ASSERT_DOUBLE_EQ(vd.lengthSquared(), 25.0);
}

TEST(Vec2Test, Normalize) {
	Vec2<int> vi(3, 4);
	Vec2<float> vf(3.0f, 4.0f);
	Vec2<double> vd(3.0, 4.0);

	Vec2<double> viNorm = vi.normalized();
	Vec2<float> vfNorm = vf.normalized();
	Vec2<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.6); ASSERT_DOUBLE_EQ(viNorm.y, 0.8);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.6f); ASSERT_FLOAT_EQ(vfNorm.y, 0.8f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.6); ASSERT_DOUBLE_EQ(vdNorm.y, 0.8);
}
TEST(Vec2Test, NormalizeZero) {
	Vec2<int> vi(0, 0);
	Vec2<float> vf(0.0f, 0.0f);
	Vec2<double> vd(0.0, 0.0);

	Vec2<double> viNorm = vi.normalized();
	Vec2<float> vfNorm = vf.normalized();
	Vec2<double> vdNorm = vd.normalized();

	ASSERT_DOUBLE_EQ(viNorm.x, 0.0); ASSERT_DOUBLE_EQ(viNorm.y, 0.0);
	ASSERT_FLOAT_EQ(vfNorm.x, 0.0f); ASSERT_FLOAT_EQ(vfNorm.y, 0.0f);
	ASSERT_DOUBLE_EQ(vdNorm.x, 0.0); ASSERT_DOUBLE_EQ(vdNorm.y, 0.0);
}

TEST(Vec2Test, DotProduct) {
	Vec2<int> vi1(1, 2);
	Vec2<int> vi2(3, 4);
	Vec2<float> vf1(1.0f, 2.0f);
	Vec2<float> vf2(3.0f, 4.0f);
	Vec2<double> vd1(1.0, 2.0);
	Vec2<double> vd2(3.0, 4.0);

	ASSERT_EQ(vi1.dot(vi2), 11);
	ASSERT_FLOAT_EQ(vf1.dot(vf2), 11.0f);
	ASSERT_DOUBLE_EQ(vd1.dot(vd2), 11.0);
}