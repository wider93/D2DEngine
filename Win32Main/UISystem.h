#pragma once
#include "ECSElements.h"
#include "ECSCall.h"
#include "globalheader.h"
#include "EventListener.h"
#include "Events.h"

class UISystem : public System<UISystem>, public EventListener
{
	using UIGroupEntities = std::vector<EntityId>;

public:
	UISystem();
	~UISystem();
	
	virtual void PreUpdate(float dt);
	virtual void Update(float dt);
	virtual void PostUpdate(float dt);

	void GetMouseOnUI(EntityId id, EntityId& get, const D2D1_POINT_2F& pos);

	std::pair<EntityId, int> GetEffectedEntity(const D2D1_POINT_2F& pos);
	bool CheckEntityId(EntityId& eid);
	void SwapOrder(UIGroupEntities& group, int targetidx);

	void RegistEvent();
	void UnRegistEvent();

	void OnMouseButtonDown(const MouseButtonDown* event);
	void OnMouseButton(const MouseButton* event);
	void OnMouseButtonUp(const MouseButtonUp* event);

private:
	UIGroupEntities _uigroups;
};
