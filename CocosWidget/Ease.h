#include <math.h>
#ifndef __EASE_H__
#define __EASE_H__

class Ease
{
public:
	static float none(float t, float b, float c, float d){
		return c * t / d + b;
	}
	static float strongIn(float t, float b, float c, float d){
		t = t / d;
		return c * t * t * t * t * t + b;
	}
	static float strongOut(float t, float b, float c, float d){
		t = t / d - 1;
		return c * (t * t * t * t * t + 1) + b;
	}
	static float strongInOut(float t, float b, float c, float d){
		t = t / d / 2;
		if (t < 1) return c / 2 * t * t * t * t * t + b;
		t = t - 2;
		return c / 2 * (t * t * t * t * t + 2) + b;
	}
	static float backIn(float t, float b, float c, float d, float s = 1.70158){
		t = t / d;
		return c * t * t * ((s + 1) * t - s) + b;
	}
	static float backOut(float t, float b, float c, float d, float s = 1.70158){
		t = t / d - 1;
		return c * (t * t * ((s + 1) * t + s) + 1) + b;
	}
	static float backInOut(float t, float b, float c, float d, float s = 1.70158){
		t = t / d / 2;
		if (t < 1){
			s = s * (1.525);
			return c / 2 * (t * t * ((s + 1) * t - s)) + b;
		}
		t = t - 2;
		s = s * (1.525);
		return c / 2 * (t * t * ((s + 1) * t + s) + 2) + b;
	}
	static float circIn(float t, float b, float c, float d){
		t = t / d;
		return -c * (sqrt(1 - t * t) - 1) + b;
	}
	static float circOut(float t, float b, float c, float d){
		t = t / d - 1;
		return c * sqrt(1 - t * t) + b;
	}
	static float circInOut(float t, float b, float c, float d){
		t = t / d / 2;
		if (t < 1) return -c / 2 * (sqrt(1 - t * t) - 1) + b;
		t = t - 2;
		return c / 2 * (sqrt(1 - t * t) + 1) + b;
	}
	static float elasticIn(float t, float b, float c, float d, float a = 0, float p = 0){
		float s;
		if (t == 0) return b;
		t = t / d;
		if (t == 1)  return b + c;
		if (!p) p = d*.3;
		if (!a || a < abs(c)){
			a = c;
			s = p / 4;
		}
		else{
			s = p / (3.141592 * 2) * asin(c / a);
		}
		t = t - 1;
		return -(a * pow(2, 10 * t) * sin((t * d - s) * 3.141592 * 2 / p)) + b;
	}
	static float elasticOut(float t, float b, float c, float d, float a = 0, float p = 0){
		float s;
		if (t == 0)  return b;
		t = t / d;
		if (t == 1) return b + c;
		if (!p) p = d*0.3;
		if (!a || a < abs(c)){
			a = c;
			s = p / 4;
		}
		else{
			s = p / (3.141592 * 2) * asin(c / a);
		}
		return(a * pow(2, -10 * t) * sin((t * d - s) * 3.141592 * 2 / p) + c + b);
	}
	static float elasticInOut(float t, float b, float c, float d, float a = 0, float p = 0){
		float s;
		if (t == 0) return b;
		t = t / d / 2;
		if (t == 2) return b + c;
		if (!p) p = d * (.3 * 1.5);
		if (!a || a < abs(c)){
			a = c;
			s = p / 4;
		}
		else{
			s = p / (3.141592 * 2) * asin(c / a);
		}
		if (t < 1){
			t = t - 1;
			return -0.5 * (a * pow(2, 10 * t) * sin((t * d - s) * 3.141592 * 2 / p)) + b;
		}
		t = t - 1;
		return a * pow(2, -10 * t) * sin((t * d - s) * 3.141592 * 2 / p) * 0.5 + c + b;
	}
	static float quadIn(float t, float b, float c, float d){
		t = t / d;
		return c * t * t + b;
	}
	static float quadOut(float t, float b, float c, float d){
		t = t / d;
		return -c * t * (t - 2) + b;
	}
	static float quadInOut(float t, float b, float c, float d){
		t = t / d * 0.5;
		if (t < 1) return c * 0.5 * t * t + b;
		t = t - 1;
		return -c * 0.5 * (t * (t - 2) - 1) + b;
	}

	static float bounceOut(float t, float b, float c, float d){
		t = t / d;
		if (t < (1 / 2.75)) {
			return c * (7.5625 * t * t) + b;
		}
		else if (t < (2 / 2.75)) {
			t = t - 1.5 / 2.75;
			return c * (7.5625 * t * t + .75) + b;
		}
		else if (t < (2.5 / 2.75)) {
			t = t - 2.25 / 2.75;
			return c * (7.5625 * t * t + .9375) + b;
		}
		else {
			t = t - 2.625 / 2.75;
			return c * (7.5625 * t * t + .984375) + b;
		}
	}

	static float bounceIn(float t, float b, float c, float d){
		return c - Ease::bounceOut(d - t, 0, c, d) + b;
	}

	static float bounceInOut(float t, float b, float c, float d){
		if (t < d * 0.5) {
			return Ease::bounceIn(t * 2, 0, c, d) * .5 + b;
		}
		else {
			return Ease::bounceOut(t * 2 - d, 0, c, d) * .5 + c * .5 + b;
		}
	}

	enum eEase
	{
		kNone,
		kStrongIn,
		kStrongOut,
		kStrongInOut,
		kBackIn,
		kBackOut,
		kBackInOut,
		kCircIn,
		kCircOut,
		kCircInOut,
		kElasticIn,
		kElasticOut,
		kElasticInOut,
		kQuadIn,
		kQuadOut,
		kQuadInOut,
		kBounceIn,
		kBounceOut,
		kbounceInOut,
	};


	/************************************************************************/
	//	GET/SET/IS
	/************************************************************************/
	static float getEaseValueById(eEase id, float t, float b, float c, float d)
	{
		float ret = -1;
		switch (id)
		{
		case kNone:				ret = Ease::none(t, b, c, d);				break;
		case kStrongIn:			ret = Ease::strongIn(t, b, c, d);			break;
		case kStrongOut:		ret = Ease::strongOut(t, b, c, d);			break;
		case kStrongInOut:		ret = Ease::strongInOut(t, b, c, d);		break;
		case kBackIn:			ret = Ease::backIn(t, b, c, d);				break;
		case kBackOut:			ret = Ease::backOut(t, b, c, d);			break;
		case kBackInOut:		ret = Ease::backInOut(t, b, c, d);			break;
		}
		return ret;
	}
protected:
private:
};


#endif