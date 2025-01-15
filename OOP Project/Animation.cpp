#include "stdafx.h"
#include "Animation.h"

void Animation::initVariables()
{
	this->animState = IDLE;
}

void Animation::initAnimations()
{
	this->animation_timer.restart();
	this->animationSwitch = true;
}

Animation::Animation(sf::Sprite* entity, int width, int height)
{
	this->initVariables();
	this->initAnimations();

	this->width = width;
	this->height = height;

	this->entity = entity;
	this->currentFrame = sf::IntRect(0, 0, this->width, this->height);
	this->entity->setTextureRect(this->currentFrame);
	this->entity->setScale(1.1f, 1.1f);
}

Animation::~Animation()
{

}

const bool& Animation::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::Sprite* Animation::getEntity()
{
	return this->entity;
}

void Animation::resetAnimationTimer()
{
	this->animation_timer.restart();
	this->animationSwitch = true;
}

void Animation::updateAnimations(short stateType, float top, float left, float maxFrameLeft)
{
	this->animState = stateType;
	// IDLE Animations
	if (this->animState == IDLE)
	{
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.35f || this->getAnimSwitch())
		{
			this->currentFrame.top = top;
			this->currentFrame.left += left;
			if (this->currentFrame.left >= maxFrameLeft)
				this->currentFrame.left = 0;
			this->animation_timer.restart();
			this->entity->setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == MOVING_LEFT)
	{
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.14f || this->getAnimSwitch())
		{
			this->currentFrame.top = top;
			this->currentFrame.left += left;
			if (this->currentFrame.left >= maxFrameLeft)
				this->currentFrame.left = 0;

			this->animation_timer.restart();
			this->entity->setTextureRect(this->currentFrame);
		}

		this->entity->setScale(-1.1f, 1.1f);
		this->entity->setOrigin(this->entity->getGlobalBounds().width / 1.1f, 0.f);
	}
	else if (this->animState == MOVING_RIGHT)
	{
		if (this->animation_timer.getElapsedTime().asSeconds() >= 0.14f || this->getAnimSwitch())
		{
			this->currentFrame.top = top;
			this->currentFrame.left += left;
			if (this->currentFrame.left >= maxFrameLeft)
				this->currentFrame.left = 0;

			this->animation_timer.restart();
			this->entity->setTextureRect(this->currentFrame);
		}

		this->entity->setScale(1.1f, 1.1f);
		this->entity->setOrigin(0.f, 0.f);
	}
	else
		this->animation_timer.restart();

}

void Animation::update(short stateType)
{
	//this->updateAnimations(stateType);
}

void Animation::render(sf::RenderTarget& target)
{
	target.draw(*this->entity);
}

