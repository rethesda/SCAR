#pragma once
#include "nlohmann/json.hpp"

namespace SCAR
{
	using json = nlohmann::json;

	using DefaultObject = RE::BGSDefaultObjectManager::DefaultObject;

	struct SCARActionData
	{
		float weight = 0.f;

		std::string IdleAnimationEditorID = "";

		float minDistance = 0.f;

		float maxDistance = 150.f;

		float startAngle = -60.f;

		float endAngle = 60.f;

		float chance = 100.f;

		std::string actionType = "RA";

		bool PerformSCARAction(RE::Actor* a_attacker, RE::Actor* a_target);

	private:
		const DefaultObject GetActionObject() const;
		const float GetStartAngle() const { return startAngle / 180.f * std::numbers::pi; };
		const float GetEndAngle() const { return endAngle / 180.f * std::numbers::pi; };
	};

	void from_json(const json& j, SCARActionData& a_data);
}