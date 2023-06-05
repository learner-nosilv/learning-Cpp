/*
   FILE NAME : Circle.h
   AUTHOR : -
   YYYYMMDD : 2023.05.21
   PURPOSE :
	수업시간에 언급한 것과 같이,
		2. 9장 ‘실습 문제’ 1 & 2 ( 제출 안함 ), 10 제출 함
			① 이 프로그램은 문제의 힌트에서 제시하는 것처럼 [그림9-13]을 이용하여 다음과 같은 파일들을 작성하시오
				: Shape.h, Shape.cpp, Circle.h, Circle.cpp, Line.h, Line.cpp, Rect.h, Rect.cpp
			② 그리고 문제의 힌트에서 제시하는 솔루션을 작성하는 데 필요한 다음 파일들은 첨부된 파일들을 사용하시오.
				이들 파일들은, 과제 기간이 상대적으로 충분하지 않을 수 있기 때문에, 솔루션 프로그램의 이해도를 높이기 위해 제공되는 것이니
				각 파일의 내용을 분석하여 솔루션 프로그램이 어떻게 작동하는 지를 이해하도록 학습하시오
				: GraphicEditor.h, GraphicEditor.cpp, UI.h, UI.cpp, Main.cpp
			③ 위의 모든 파일들을 다음의 프로젝트 파일안에서 조합한 후, 문제에서 제시한 출력결과와 같은 결과가 나오도록 실행하시오
				: ShapeGraphicEditorUI
*/

#ifndef CIRCLE
#define CIRCLE

class Circle : public Shape {
protected:
	virtual void draw();
};

#endif