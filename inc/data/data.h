#ifndef DATA_H
#define DATA_H

#include <vector>
#include <map>
#include <QString>
#include <QJsonObject>

struct Element {
		Element() {}
		virtual ~Element() = 0;

		enum class Enum {
			null = -1, water, fire, earth, wind
		};

		static std::vector<Enum> getElements() {
				return std::vector<Enum> {
					Enum::water, Enum::fire, Enum::earth, Enum::wind
				};
		}

		static QString toQString(Enum element) {
			const std::map<Enum, const QString> mapString {
				{Enum::water, "Eau"},
				{Enum::fire, "Feu"},
				{Enum::earth, "Terre"},
				{Enum::wind, "Air"}
			};

			auto mapPart = mapString.find(element);

			return (mapPart == mapString.end() ? "Out of range" : mapPart->second);
		}

		static Enum toEnum(QString string) {
			const std::map<const QString, Enum> mapEnum {
				{"Eau", Enum::water},
				{"Feu", Enum::fire},
				{"Terre", Enum::earth},
				{"Air", Enum::wind}
			};

			auto mapPart = mapEnum.find(string);

			return (mapPart == mapEnum.end() ? Enum::null : mapPart->second);
		}
};

struct Form {
		enum class Enum {
			null = -1, circle, square, horizontalLine,
			verticalLine, normalCross, diagonalCross
		};

		static std::vector<Enum> getForms() {
			return std::vector<Enum> {
				Enum::circle, Enum::square, Enum::horizontalLine,
				Enum::verticalLine, Enum::normalCross, Enum::diagonalCross
			};
		}

		static QString toQString(Enum form)
		{
			const std::map<Enum, const QString> mapString {
				{Enum::circle, "Cercle"},
				{Enum::square, "Carré"},
				{Enum::horizontalLine, "Ligne horizontale"},
				{Enum::verticalLine, "Ligne verticale"},
				{Enum::normalCross, "Croix"},
				{Enum::diagonalCross, "Croix diagonale"}
			};

			auto mapPart = mapString.find(form);

			return (mapPart == mapString.end() ? "Out of range" : mapPart->second);
		}

		static Enum toEnum(QString string) {
			const std::map<const QString, Enum> mapEnum {
				{"Cercle", Enum::circle},
				{"Carré", Enum::square},
				{"Ligne horizontale", Enum::horizontalLine},
				{"Ligne verticale", Enum::verticalLine},
				{"Croix", Enum::normalCross},
				{"Croix diagonale", Enum::diagonalCross}
			};

			auto mapPart = mapEnum.find(string);

			return (mapPart == mapEnum.end() ? Enum::null : mapPart->second);
		}
};

struct TypeLaunch {
		enum class Enum {
			null = -1, normal, line
		};
		static std::vector<Enum> getTypesLaunches() {
			return std::vector<Enum> {
				Enum::normal, Enum::line
			};
		}

		static QString toQString(Enum typeLaunch)
		{
			const std::map<Enum, const QString> mapString {
				{Enum::normal, "Normal"},
				{Enum::line, "En ligne"}
			};

			auto mapPart = mapString.find(typeLaunch);

			return (mapPart == mapString.end() ? "Out of range" : mapPart->second);
		}

		static Enum toEnum(QString string) {
			const std::map<const QString, Enum> mapEnum {
				{"Normal", Enum::normal},
				{"En ligne", Enum::line}
			};

			auto mapPart = mapEnum.find(string);

			return (mapPart == mapEnum.end() ? Enum::null : mapPart->second);
		}
};
#endif // DATA_H
