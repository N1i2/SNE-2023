#include"stdafx.h"

namespace Error {
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY(102,"�������� -in �� ������"), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),
		ERROR_ENTRY(109,"������������� ���������� ��������� �������� ������ ���������"),
		ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111, "������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112, "������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(113,"������ ��� �������� ����� ��������� (-out)"), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "{ LEXICAL } ������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(201, "{ LEXICAL } �������� ������ ������� ������"),
		ERROR_ENTRY(202, "{ LEXICAL } ������������ ������� ������"),
		ERROR_ENTRY(203, "{ LEXICAL } �������� ������ ������� ���������������"),
		ERROR_ENTRY(204, "{ LEXICAL } ������������ ������� ���������������"),
		ERROR_ENTRY(205, "{ LEXICAL } ����������� ������������������ ��������"),
		ERROR_ENTRY_NODEF(206),
		ERROR_ENTRY(207, "{ LEXICAL } �������� ������ �������� �������� ������� ���������"),
		ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "{ SEMANTIC } ������� ���������� ��������� �������"),
		ERROR_ENTRY(301, "{ SEMANTIC } ������� ����� ����� ����� ����� � main"),
		ERROR_ENTRY(302, "{ SEMANTIC } �� ������� ����� ����� � main"),
		ERROR_ENTRY(303, "{ SEMANTIC } �������� ������ ����������� ��������"),
		ERROR_ENTRY(304, "{ SEMANTIC } ������������ ��� ������ ��� ���������"),
		ERROR_ENTRY(305, "{ SEMANTIC } ������������� �������������"),
		ERROR_ENTRY(306, "{ SEMANTIC } ������� �������������� ����������"),
		ERROR_ENTRY(307, "{ SEMANTIC } ������� ����������� ������������ �������"),
		ERROR_ENTRY(308, "{ SEMANTIC } ������� ���������� ���������� �������"),
		ERROR_ENTRY(309, "{ SEMANTIC } ������������ ����������� � ���������� ���������� �������"),
		ERROR_ENTRY(310, "{ SEMANTIC } ������������� �������� � �������"),
		ERROR_ENTRY_NODEF(311),
		ERROR_ENTRY(312, "{ SEMANTIC } ������������� ����� ������"),
		ERROR_ENTRY(313, "{ SEMANTIC } ������������� �������� � �������� ������ � ���������"),
		ERROR_ENTRY(314, "{ SEMANTIC } ������� ���������� �������� ��� ������"),
		ERROR_ENTRY(315, "{ SEMANTIC } ������������ ����� ������ � �������� ��������� ��� �����"),
		ERROR_ENTRY(316, "{ SEMANTIC } ��� ������ � �������� ��������� �� �������� boolean"),
		ERROR_ENTRY_NODEF(317),
		ERROR_ENTRY(318, "{ SEMANTIC } �������� ���������� ���� string ������� �� ������� ���������� ��������"),
		ERROR_ENTRY_NODEF(319),ERROR_ENTRY_NODEF(320),ERROR_ENTRY_NODEF(321),
		ERROR_ENTRY_NODEF(322),ERROR_ENTRY_NODEF(323),ERROR_ENTRY_NODEF(324),ERROR_ENTRY_NODEF(325),ERROR_ENTRY_NODEF(326),
		ERROR_ENTRY_NODEF(327),ERROR_ENTRY_NODEF(328),ERROR_ENTRY_NODEF(329),
		ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),ERROR_ENTRY_NODEF10(350),ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),
		ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600,"{ SYNTACTIC } �������� ��������� ���������"),
		ERROR_ENTRY(601,"{ SYNTACTIC } �������� �����������  �������"),
		ERROR_ENTRY(602,"{ SYNTACTIC } ������ � ���������"),
		ERROR_ENTRY(603,"{ SYNTACTIC } ������ ���������� ������� ��� ���������"),
		ERROR_ENTRY(604,"{ SYNTACTIC } ������ � ���������� ������� ��� ���������"),
		ERROR_ENTRY(605,"{ SYNTACTIC } �������� ��������� ������"),
		ERROR_ENTRY(606,"{ SYNTACTIC } �������� ��������� ��������� "),
		ERROR_ENTRY(607,"{ SYNTACTIC } ������ � ���������� ���������� �������"),
		ERROR_ENTRY(608,"{ SYNTACTIC } �������� ������� ����� ��� �������� ���������"),
		ERROR_ENTRY(609,"{ SYNTACTIC } ������ ��� ������ �������"),
		ERROR_ENTRY(610,"{ SYNTACTIC } ������ � ���������"),
		ERROR_ENTRY(611,"{ SYNTACTIC } �������� ����������� ����� ��� ��������� ���������"),
		ERROR_ENTRY(612,"{ SYNTACTIC } �������������� ���������� ��������� �������� ������ "),ERROR_ENTRY_NODEF(613),ERROR_ENTRY_NODEF(614),ERROR_ENTRY_NODEF(615),ERROR_ENTRY_NODEF(616),ERROR_ENTRY_NODEF(617),
		ERROR_ENTRY_NODEF(618),ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620),ERROR_ENTRY_NODEF10(630),ERROR_ENTRY_NODEF10(640),ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660),ERROR_ENTRY_NODEF10(670),ERROR_ENTRY_NODEF10(680),ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			return errors[id];
		}
		else {
			return errors[0];
		}
	}

	ERROR geterrorin(int id, int line = -1, int col = -1) {
		if (id > 0 && id < ERROR_MAX_ENTRY) {
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else {
			return errors[0];
		}
	}
}